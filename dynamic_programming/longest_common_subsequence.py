import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QLineEdit, QPushButton, QVBoxLayout, QTableWidget, QTableWidgetItem, QTextEdit
from PyQt5.QtGui import QFont, QBrush, QColor
from PyQt5.QtCore import Qt

def lcs(x, y):
    m = len(x)
    n = len(y)
    
    # create table
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    directions = [[''] * (n + 1) for _ in range(m + 1)]
    
    # Fill the dp table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            # if equal increment 1
            if x[i - 1] == y[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                directions[i][j] = '↖'  # Diagonal arrow
            else:
                if dp[i - 1][j] >= dp[i][j - 1]:
                    dp[i][j] = dp[i - 1][j]
                    directions[i][j] = '↑'  # Up arrow
                else:
                    dp[i][j] = dp[i][j - 1]
                    directions[i][j] = '←'  # Left arrow
    
    # Reconstruct the LCS
    i, j = m, n
    lcs_sequence = []
    
    while i > 0 and j > 0:
        if x[i - 1] == y[j - 1]:
            lcs_sequence.append(x[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] >= dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    lcs_sequence.reverse()
    return dp, ''.join(lcs_sequence), directions

class LCSApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Longest Common Subsequence Finder')
        self.setGeometry(100, 100, 800, 600)
        
        self.seq1_label = QLabel('Sequence 1:', self)
        self.seq1_label.setFont(QFont('Arial', 12))
        self.seq1_input = QLineEdit(self)
        self.seq1_input.setFont(QFont('Arial', 12))
        
        self.seq2_label = QLabel('Sequence 2:', self)
        self.seq2_label.setFont(QFont('Arial', 12))
        self.seq2_input = QLineEdit(self)
        self.seq2_input.setFont(QFont('Arial', 12))
        
        self.compute_button = QPushButton('Compute LCS', self)
        self.compute_button.setFont(QFont('Arial', 12))
        self.compute_button.clicked.connect(self.computeLCS)
        
        self.lcs_label = QLabel('LCS:', self)
        self.lcs_label.setFont(QFont('Arial', 12))
        self.lcs_output = QLineEdit(self)
        self.lcs_output.setFont(QFont('Arial', 12))
        self.lcs_output.setReadOnly(True)
        
        self.dp_table = QTableWidget(self)
        self.dp_table.setFont(QFont('Arial', 10))
        
        layout = QVBoxLayout()
        layout.addWidget(self.seq1_label)
        layout.addWidget(self.seq1_input)
        layout.addWidget(self.seq2_label)
        layout.addWidget(self.seq2_input)
        layout.addWidget(self.compute_button)
        layout.addWidget(self.lcs_label)
        layout.addWidget(self.lcs_output)
        layout.addWidget(self.dp_table)
        
        self.setLayout(layout)
    
    def computeLCS(self):
        seq1 = self.seq1_input.text().split()
        seq2 = self.seq2_input.text().split()
        
        dp, lcs_seq, directions = lcs(seq1, seq2)
        
        self.lcs_output.setText(lcs_seq)
        
        # Display the dp table with directions
        rows = len(dp)
        cols = len(dp[0])
        self.dp_table.setRowCount(rows)
        self.dp_table.setColumnCount(cols)
        
        for i in range(rows):
            for j in range(cols):
                item = QTableWidgetItem(f"{dp[i][j]} {directions[i][j]}")
                item.setTextAlignment(Qt.AlignCenter)
                if directions[i][j] == '↖':
                    item.setBackground(QBrush(QColor(144, 238, 144)))  # Light green for diagonal match
                elif directions[i][j] == '↑':
                    item.setBackground(QBrush(QColor(173, 216, 230)))  # Light blue for up
                elif directions[i][j] == '←':
                    item.setBackground(QBrush(QColor(255, 228, 225)))  # Light pink for left
                self.dp_table.setItem(i, j, item)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = LCSApp()
    ex.show()
    sys.exit(app.exec_())
