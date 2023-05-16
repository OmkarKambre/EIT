#include<iostream>
#include<string>

using namespace std;

string round_keys[0];

int data[64] = {1,1,1,1,0,0,0,0,
                1,0,1,0,1,0,1,0,
                1,0,1,0,1,0,1,0,
                0,0,1,1,0,0,1,1,
                1,1,1,1,0,0,0,0,
                1,0,1,0,1,0,1,0,
                1,0,1,0,1,0,1,0,
                0,0,1,1,0,0,1,1};

int shiftedData[64];

void print_array(int array_print[])
{
  for(int i=0;i<sizeof(array_print)/sizeof(array_print[0]);i++)
  {
      cout<<array_print[i];
  }
}
void shift_left(int shift_data , int d[], int size)
{
   shiftedData[0] = d[63];
   for(int i=1;i<size;i++)
   {
       shiftedData[i] += d[i+1];
   }
}
void shift_right_once(int d[],int size)
{
   shiftedData[0] = d[63];
   for(int i=1;i<size;i++)
   {
       shiftedData[i] += d[i-1];
   }
}

void convert64to56(int input[], int output[])
{
    int outputIndex = 0;
    for(int i=0;i<64;i++)
    {
        if((i+1) % 8 != 0)
            {
              //skip every 8th element
              output[outputIndex] = input[i];
              outputIndex++;
            }
    }
}

int main()
{
  int LO[32],RO[32],j=32,key[56],LO_key[28],RO_key[28];

  for(int c:data)
  {
      cout<<c;
  }
  cout<<endl;

  shift_right_once(data , 64);

  cout<< "Right shifted data: \n";

  for(int c: shiftedData)
  {
      cout<<c;
  }
  cout<<endl;

  for(int i=0;i<sizeof(LO)/sizeof(LO[0]);i++)
  {
      LO[i] = shiftedData[i];
  }

  for(int i=0;i<sizeof(RO)/sizeof(RO[0]);i++)
  {
      RO[i] = shiftedData[j];
      j++;
  }

 cout<<"Left data: \n";
 for(int c : LO)
 {
     cout<<c;
 }
 cout<<endl;

 cout<<"Right data: \n";
 for(int c : RO)
 {
     cout<<c;
 }
 cout<<endl;

 //key generation
 convert64to56(data,key);
 cout<<"56 bit key: \n";
  for(int c : key)
 {
     cout<<c;
 }
 cout<<endl;

for(int i=0;i<sizeof(LO_key)/sizeof(LO_key[0]);i++)
{
    LO_key[i] = key[i];
}
j=28;
for(int i=0;i<sizeof(RO_key)/sizeof(RO_key[0]);i++)
{
    RO_key[i] = key[j];
    j++;
}
cout<<"Left key data: \n";
for(int c: LO_key)
{
    cout<< c;

}
cout<<endl;

cout<<"Right key data: \n";
for(int c: RO_key)
{
    cout<< c;

}
cout<<endl;

return 0;
}
