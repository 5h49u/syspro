#include<stdio.h>
int hits=0,miss=0,p=0;
void print(int frame_size,int frame[]) {
     for(int i=0;i<frame_size;i++){
          if(frame[i]==-1){
          printf(" -");
          }
          else
          printf(" %d",frame[i]);
     }
     printf("\n");
}
void add(int frame_size,int frame[],int reference) {
     int flag=1;
     for(int i=0;i<frame_size;i++) {
          if(frame[i]==reference) {
          hits++;
          printf(" Hit for %d ",reference);
          flag=0;
          break;
          }
          else
          if(frame[i]==-1) {
          miss++;
          printf("Fault for %d ",reference);
          frame[i]=reference;
          flag=0;
          break;
          }
     }
     if(flag==1) {
     frame[p]=reference;
     p=(p+1)%frame_size;
     miss++;
     printf("Fault for %d ",reference);
     
     }
     print(frame_size,frame);

}


int main() {
     int frame_size,r;
     printf("Enter the frame size\n");
     scanf("%d",&frame_size);
     int frame[frame_size];
     int referenceNumber;
     printf("Enter the number of references\n");
     scanf("%d",&referenceNumber);
     int references[referenceNumber];
     for(int i=0;i<frame_size;i++){
     frame[i]=-1;
     }
     print(frame_size,frame);
     for(int i=0;i<referenceNumber;i++) {
          scanf("%d",&r);
          add(frame_size,frame,r);
          
     }
     printf("The number of hits are %d and the number of faults are %d\n",hits,miss);
     
}
