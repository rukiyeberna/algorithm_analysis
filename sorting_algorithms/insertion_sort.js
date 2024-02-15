/*elimizde 6 elemanli karisik siralanmis bir sayi dizisi olsun.--> n = 6*/
/*insertion sort algoritmasi için araya yerleştirme algoritmasi diyebiliriz.*/
/*------pseudocode--------*/
/* for(i=1;i<n;i++)
{
    temp = A[i];
    j=i-1;

    while(j<=0 && A[j] > temp )
    {
        // bu kosulu sagladigi durumda shift yapiyoruz 
    }

}*/


let A = [5, 4, 10 ,1 ,6, 2, ];
let arrSize = A.length;

function insertionSort(arrSize,A)
{
    let i,j,temp;

    for(i=1; i< arrSize; i++)
    {
        temp = A[i];
        j= i-1;

        while (j>=0 && A[j]> temp) 
        {
            A[j+1] = A[j];
            j--;    
        }
        A[j+1] = temp;
    }
}
function printArray(arrSize,A)
{
    let i;
    for ( i=0; i<arrSize; i++) 
    {
        console.log(A[i] + "  "); 
    }
    console.log(" ");
}

 
// callback
printArray(arrSize,A);
insertionSort(arrSize,A);
printArray(arrSize,A);
