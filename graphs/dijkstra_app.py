import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QVBoxLayout, QWidget, QGraphicsView, QGraphicsScene, QGraphicsEllipseItem, QGraphicsLineItem, QGraphicsTextItem, QDockWidget, QLineEdit, QInputDialog, QColorDialog
from PyQt5.QtCore import QRectF, Qt, QPointF, QLineF
from PyQt5.QtGui import QPen, QColor

class GraphWidget(QGraphicsView):
    def __init__(self):
        super().__init__()
        self.scene = QGraphicsScene(self)
        self.setScene(self.scene)
        self.nodes = []
        self.edges = []
        self.node_count = 0

    def add_node(self, x, y, name):
        node = QGraphicsEllipseItem(QRectF(x - 10, y - 10, 20, 20))
        node.setBrush(Qt.blue)
        node.setFlag(QGraphicsEllipseItem.ItemIsMovable)
        self.scene.addItem(node)
        self.nodes.append((node, name))
        
        text = QGraphicsTextItem(name)
        text.setDefaultTextColor(Qt.white)
        text.setPos(x - 10, y - 10)
        self.scene.addItem(text)
        return node

    def add_edge(self, node1, node2, weight, color):
        line = QGraphicsLineItem(QLineF(node1[0].pos(), node2[0].pos()))
        pen = QPen(color, 2)
        line.setPen(pen)
        self.scene.addItem(line)
        self.edges.append((line, node1, node2, weight))
        
        mid_point = (node1[0].pos() + node2[0].pos()) / 2
        text = QGraphicsTextItem(str(weight))
        text.setDefaultTextColor(Qt.black)
        text.setPos(mid_point.x(), mid_point.y())
        self.scene.addItem(text)

    def dijkstra(self, start_node):
        import heapq
        distances = {node: float('infinity') for node, _ in self.nodes}
        distances[start_node] = 0
        pq = [(0, start_node)]
        while pq:
            current_distance, current_node = heapq.heappop(pq)
            if current_distance > distances[current_node]:
                continue
            for edge, node1, node2, weight in self.edges:
                if node1 == current_node:
                    neighbor = node2
                elif node2 == current_node:
                    neighbor = node1
                else:
                    continue
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))
        return distances

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.graph_widget = GraphWidget()
        self.setCentralWidget(self.graph_widget)
        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Dijkstra Algorithm Visualization')
        self.setGeometry(100, 100, 800, 600)
        
        add_node_button = QPushButton('Add Node')
        add_node_button.clicked.connect(self.add_node)

        add_edge_button = QPushButton('Add Edge')
        add_edge_button.clicked.connect(self.add_edge)

        run_dijkstra_button = QPushButton('Run Dijkstra')
        run_dijkstra_button.clicked.connect(self.run_dijkstra)

        layout = QVBoxLayout()
        layout.addWidget(add_node_button)
        layout.addWidget(add_edge_button)
        layout.addWidget(run_dijkstra_button)

        container = QWidget()
        container.setLayout(layout)
        
        dock_widget = QDockWidget('Controls', self)
        dock_widget.setWidget(container)
        self.addDockWidget(Qt.LeftDockWidgetArea, dock_widget)

    def add_node(self):
        name, ok = QInputDialog.getText(self, 'Node Name', 'Enter node name:')
        if ok:
            pos = self.graph_widget.mapToScene(self.graph_widget.viewport().rect().center())
            self.graph_widget.add_node(pos.x(), pos.y(), name)

    def add_edge(self):
        if len(self.graph_widget.nodes) >= 2:
            node1, ok1 = QInputDialog.getItem(self, 'Select First Node', 'Select first node:', [name for _, name in self.graph_widget.nodes], 0, False)
            node2, ok2 = QInputDialog.getItem(self, 'Select Second Node', 'Select second node:', [name for _, name in self.graph_widget.nodes], 0, False)
            weight, ok3 = QInputDialog.getInt(self, 'Edge Weight', 'Enter edge weight:', 1, 1, 100, 1)
            color = QColorDialog.getColor()
            if ok1 and ok2 and ok3 and color.isValid():
                node1_item = next(node for node in self.graph_widget.nodes if node[1] == node1)
                node2_item = next(node for node in self.graph_widget.nodes if node[1] == node2)
                self.graph_widget.add_edge(node1_item, node2_item, weight, color)

    def run_dijkstra(self):
        if self.graph_widget.nodes:
            start_node, ok = QInputDialog.getItem(self, 'Select Start Node', 'Select start node:', [name for _, name in self.graph_widget.nodes], 0, False)
            if ok:
                start_node_item = next(node for node in self.graph_widget.nodes if node[1] == start_node)
                distances = self.graph_widget.dijkstra(start_node_item)
                print("Shortest distances from start node:")
                for node, name in self.graph_widget.nodes:
                    print(f"Node {name}: {distances[node]}")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
