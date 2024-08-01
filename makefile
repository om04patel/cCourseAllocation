cCourseAllocation: cCourseAllocation.o cCourseAllocationMain.o
	gcc cCourseAllocation.o cCourseAllocationMain.o -lm -o cCourseAllocation

cCourseAllocation.o: cCourseAllocation.c
	gcc -Wall -std=c99 -c cCourseAllocation.c

cCourseAllocationMain.o: cCourseAllocationMain.c
	gcc -Wall -std=c99 -c cCourseAllocationMain.c

clean:
	rm *.o cCourseAllocation
