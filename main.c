#include <unistd.h>
#include "pbPlots.h"
#include "supportLib.h"
#include "Methods.h"

int m = 100000000;

float* MaxOfThree(float n1, float n2, float n3){
float *maxArr = (float *)malloc(sizeof(float)*3);
if (n1 > n2 && n1 > n3){
        maxArr[0] = n1;
        maxArr[1] = n2;
        maxArr[2] = n3;
}
    else if (n2 > n1 && n2 > n3){
        maxArr[0] = n2;
        maxArr[1] = n1;
        maxArr[2] = n3;
}
    else{
        maxArr[0] = n3;
        maxArr[1] = n1;
        maxArr[2] = n2;
}
return maxArr;
}

//void PlotGraph(float plotArr[], char *fileName){
//	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
//
//	double xs[] = {0, m};
//	double ys[] = {0, plotArr[0]};
//
//	DrawScatterPlot(canvasReference, 1366, 768, xs, 2, ys, 2);
//
//	double x1 = MapXCoordinateAutoSettings(0, canvasReference->image, xs, 2);
//	double y1 = MapYCoordinateAutoSettings(0, canvasReference->image, ys, 2);
//
//	double x2 = MapXCoordinateAutoSettings(m, canvasReference->image, xs, 2);
//	double y2 = MapYCoordinateAutoSettings(plotArr[1], canvasReference->image, ys, 2);
//
//	double a1 = MapXCoordinateAutoSettings(0, canvasReference->image, xs, 2);
//	double b1 = MapYCoordinateAutoSettings(0, canvasReference->image, ys, 2);
//
//	double a2 = MapXCoordinateAutoSettings(m, canvasReference->image, xs, 2);
//	double b2 = MapYCoordinateAutoSettings(plotArr[2], canvasReference->image, ys, 2);
//
//	DrawLine(canvasReference->image, x1, y1, x2, y2, 2.1, GetGray(0.175));
//	DrawLine(canvasReference->image, a1, b1, a2, b2, 2.1, CreateRGBAColor(0.92, 0.20, 0.20, 1));
//	size_t length;
//	double *pngData = ConvertToPNG(&length, canvasReference->image);
//	WriteToFile(pngData, length, fileName);
//}

void Display(){
	printf("\t  Linear Search     Binary Search     Ternary Search     Jump Search     Interpolation Search\n");
	printf("Serial       %f          %f          %f          %f           %f\n", timespent[0],timespent[1],timespent[2],timespent[3],timespent[4]);
	printf("Pthread      %f          %f          %f          %f           %f\n", timespent[5],timespent[6],timespent[7],timespent[8],timespent[9]);
	printf("OpenMP       %f          %f          %f          %f           %f\n", timespent[10],timespent[11],timespent[12],timespent[13],timespent[14]);
	
	FILE *fptr = fopen("ComparedTimes.txt", "w");
	int k;
	if (fptr == NULL){
		printf("Error Reading File\n");
		exit(0);
	}

	for (k = 0; k < 15; ++k){
		fprintf(fptr, "%f\n", timespent[k]);
	}
	fclose(fptr);
	
	float *LSArr;
	float *BSArr;
	float *TSArr;
	float *JSArr;
	float *ISArr;
	LSArr = MaxOfThree(timespent[0], timespent[5], timespent[10]);
	BSArr = MaxOfThree(timespent[1], timespent[6], timespent[11]);
	TSArr = MaxOfThree(timespent[2], timespent[7], timespent[12]);
	JSArr = MaxOfThree(timespent[3], timespent[8], timespent[13]);
	ISArr = MaxOfThree(timespent[4], timespent[9], timespent[14]);
	//PlotGraph(LSArr, "LinearSearch.png");
	//PlotGraph(BSArr, "BinarySearch.png");
	//PlotGraph(TSArr, "TernarySearch.png");
	//PlotGraph(JSArr, "JumpSearch.png");
	//PlotGraph(ISArr, "InterpolationSearch.png");
}

void DisplayByThreads(){
	printf("=== PTHREADS ===\n");
	printf("== Linear Search ==\n");
	printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", LST1PT[0], LST1PT[1],LST1PT[2],LST1PT[3],LST1PT[4],LST1PT[5],LST1PT[6],LST1PT[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", LST2PT[0], LST2PT[1],LST2PT[2],LST2PT[3],LST2PT[4],LST2PT[5],LST2PT[6],LST2PT[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", LST4PT[0], LST4PT[1],LST4PT[2],LST4PT[3],LST4PT[4],LST4PT[5],LST4PT[6],LST4PT[7]);
	
	printf("\n== Binary Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", BST1PT[0], BST1PT[1],BST1PT[2],BST1PT[3],BST1PT[4],BST1PT[5],BST1PT[6],BST1PT[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", BST2PT[0], BST2PT[1],BST2PT[2],BST2PT[3],BST2PT[4],BST2PT[5],BST2PT[6],BST2PT[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", BST4PT[0], BST4PT[1],BST4PT[2],BST4PT[3],BST4PT[4],BST4PT[5],BST4PT[6],BST4PT[7]);
	
	printf("\n== Ternary Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", TST1PT[0], TST1PT[1],TST1PT[2],TST1PT[3],TST1PT[4],TST1PT[5],TST1PT[6],TST1PT[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", TST2PT[0], TST2PT[1],TST2PT[2],TST2PT[3],TST2PT[4],TST2PT[5],TST2PT[6],TST2PT[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", TST4PT[0], TST4PT[1],TST4PT[2],TST4PT[3],TST4PT[4],TST4PT[5],TST4PT[6],TST4PT[7]);
	
	printf("\n== Jump Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", JST1PT[0], JST1PT[1],JST1PT[2],JST1PT[3],JST1PT[4],JST1PT[5],JST1PT[6],JST1PT[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", JST2PT[0], JST2PT[1],JST2PT[2],JST2PT[3],JST2PT[4],JST2PT[5],JST2PT[6],JST2PT[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", JST4PT[0], JST4PT[1],JST4PT[2],JST4PT[3],JST4PT[4],JST4PT[5],JST4PT[6],JST4PT[7]);

	printf("\n== Interpolation Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", IST1PT[0], IST1PT[1],IST1PT[2],IST1PT[3],IST1PT[4],IST1PT[5],IST1PT[6],IST1PT[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", IST2PT[0], IST2PT[1],IST2PT[2],IST2PT[3],IST2PT[4],IST2PT[5],IST2PT[6],IST2PT[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", IST4PT[0], IST4PT[1],IST4PT[2],IST4PT[3],IST4PT[4],IST4PT[5],IST4PT[6],IST4PT[7]);
	
	
	printf("\n\n");
	printf("=== OMP ===\n");
	printf("== Linear Search ==\n");
	
	printf("\n== Binary Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", BST1OMP[0], BST1OMP[1],BST1OMP[2],BST1OMP[3],BST1OMP[4],BST1OMP[5],BST1OMP[6],BST1OMP[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", BST2OMP[0], BST2OMP[1],BST2OMP[2],BST2OMP[3],BST2OMP[4],BST2OMP[5],BST2OMP[6],BST2OMP[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", BST4OMP[0], BST4OMP[1],BST4OMP[2],BST4OMP[3],BST4OMP[4],BST4OMP[5],BST4OMP[6],BST4OMP[7]);
	
	printf("\n== Ternary Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", TST1OMP[0], TST1OMP[1],TST1OMP[2],TST1OMP[3],TST1OMP[4],TST1OMP[5],TST1OMP[6],TST1OMP[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", TST2OMP[0], TST2OMP[1],TST2OMP[2],TST2OMP[3],TST2OMP[4],TST2OMP[5],TST2OMP[6],TST2OMP[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", TST4OMP[0], TST4OMP[1],TST4OMP[2],TST4OMP[3],TST4OMP[4],TST4OMP[5],TST4OMP[6],TST4OMP[7]);
	
	printf("\n== Jump Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", JST1OMP[0], JST1OMP[1],JST1OMP[2],JST1OMP[3],JST1OMP[4],JST1OMP[5],JST1OMP[6],JST1OMP[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", JST2OMP[0], JST2OMP[1],JST2OMP[2],JST2OMP[3],JST2OMP[4],JST2OMP[5],JST2OMP[6],JST2OMP[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", JST4OMP[0], JST4OMP[1],JST4OMP[2],JST4OMP[3],JST4OMP[4],JST4OMP[5],JST4OMP[6],JST4OMP[7]);

	printf("\n== Interpolation Search ==\n");
printf("\t16 \t    256           4096           65536          1048576            16777216           67108864            100000000\n");
	printf("T1  %f     %f       %f       %f         %f           %f           %f             %f  \n", IST1OMP[0], IST1OMP[1],IST1OMP[2],IST1OMP[3],IST1OMP[4],IST1OMP[5],IST1OMP[6],IST1OMP[7]);
	printf("T2  %f     %f       %f       %f         %f           %f           %f             %f  \n", IST2OMP[0], IST2OMP[1],IST2OMP[2],IST2OMP[3],IST2OMP[4],IST2OMP[5],IST2OMP[6],IST2OMP[7]);
	printf("T4  %f     %f       %f       %f         %f           %f           %f             %f  \n", IST4OMP[0], IST4OMP[1],IST4OMP[2],IST4OMP[3],IST4OMP[4],IST4OMP[5],IST4OMP[6],IST4OMP[7]);
}

void StoreInFile(FILE *fptr, float pltArr[]){
	int j;
	for(j=0; j<8; j++){
		fprintf(fptr, "%f ", pltArr[j]*pow(10,9));
	}
	fprintf(fptr, "\n");
}

void file(){
	FILE *fptr = fopen("extended.txt", "w");
	if (fptr == NULL){
	printf("Error Reading File\n");
	exit(0);
	}
	StoreInFile(fptr, LST1PT);
	StoreInFile(fptr, LST2PT);
	StoreInFile(fptr, LST4PT);
	StoreInFile(fptr, BST1PT);
	StoreInFile(fptr, BST2PT);
	StoreInFile(fptr, BST4PT);
	StoreInFile(fptr, TST1PT);
	StoreInFile(fptr, TST2PT);
	StoreInFile(fptr, TST4PT);
	StoreInFile(fptr, JST1PT);
	StoreInFile(fptr, JST2PT);
	StoreInFile(fptr, JST4PT);
	StoreInFile(fptr, IST1PT);
	StoreInFile(fptr, IST2PT);
	StoreInFile(fptr, IST4PT);

	StoreInFile(fptr, BST1OMP);
	StoreInFile(fptr, BST2OMP);
	StoreInFile(fptr, BST4OMP);
	StoreInFile(fptr, TST1OMP);
	StoreInFile(fptr, TST2OMP);
	StoreInFile(fptr, TST4OMP);
	StoreInFile(fptr, JST1OMP);
	StoreInFile(fptr, JST2OMP);
	StoreInFile(fptr, JST4OMP);
	StoreInFile(fptr, IST1OMP);
	StoreInFile(fptr, IST2OMP);
	StoreInFile(fptr, IST4OMP);
	fclose(fptr);
}


void testSerial(int *arr, int key, int m, int choice){
	SerialProgramming(arr, key, m, choice);
}

void testParal(int *arr, int key, int m, int choice){
	OMPProg(arr, key, m, choice);
}

int main(){
//	int i,j;
//	
//    int key;
//	
//    printf("Enter key: ");
////    scanf("%d", &key);
//    int choice;
//    choice = 1;
//    int k;
//    for(int i=4; i<=24; i=i+4){
//        	m=pow(2,i);

		m = 100000000;
//		FILE *fptr = fopen("data.txt", "w");
//		if (fptr == NULL){
//		printf("Error Reading File\n");
//		exit(0);
//		}
//	
//		int i =0 ;
//		for (i = 0; i < m; ++i){
//		fprintf(fptr, "%d\n", i);
//		}
//		fclose(fptr);
//
//        SerialProgramming(arr, m-1, m, choice);
//    	OMPProg(arr, m-1, m, choice);
//    }
//		int *arr = (int *)malloc(sizeof(int)*m);
//
//		if (myFile == NULL){
//		printf("Error Reading File222\n");
//		exit(0);
//		}
//
//		for (k = 0; k < m; k++){
//		fscanf(myFile, "%d,", arr+k);
//		}
//		
//        SerialProgramming(arr, m-1, m, choice);
//        PthreadProgramming(arr, m-1, m, choice);
//    	OMPProg(arr, m-1, m, choice);
//	m=100000000;
//		FILE *myFile1;
//		myFile1 = fopen("data.txt", "r");
//		int *arr1 = (int *)malloc(sizeof(int)*m);
//
//		if (myFile1 == NULL){
//		printf("Error Reading File222\n");
//		exit(0);
//		}
//
//		for (i = 0; i < m; i++){
//		fscanf(myFile1, "%d,", arr1+i);
//		}
//        SerialProgramming(arr1, m-1, m, choice);
//        PthreadProgramming(arr1, m-1, m, choice);
//    	OMPProg(arr1, m-1, m, choice);
//    	
//    	file();
//    	
//    	DisplayByThreads();
//    	Display();
//    

	
	FILE *myFile2;
   
	myFile2 = fopen("data.txt", "r");
	int *arr = (int *)malloc(sizeof(int)*m);

	if (myFile2 == NULL){
	printf("Error Reading File222\n");
	exit(0);
	}
	int k2 =0;
	for (k2 = 0; k2 < m; k2++){
	fscanf(myFile2, "%d,", arr+k2);
	}

	fclose(myFile2);
	int key = 0; int choice = 1;
	scanf("%d", &key);
	testSerial(arr,key,m,choice);
	testParal(arr,key,m,choice);
//	SerialProgramming(arr, key, m, choice);
//    OMPProg(arr, key, m, choice);

//	DisplayByThreads();
//	Display();

    return 0;
}

