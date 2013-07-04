#include <cstdlib>
#include <iostream>

using namespace std;

class candle
{
      protected:
        char * info;
        double open;
        double high;
        double low;
        double close;     
        unsigned long date;
        unsigned long time;
        int discr;
        unsigned long volume;// kilkist lotov
        unsigned long openint;
      public:
        candle();// constructors
        candle(char * newinfo, double newopen, double newhigh, double newlow, double newclose, unsigned long newvolume);
        candle(const candle &x);
        ~candle();// destructor
        char * getInfo();
        void setInfo(char * newInfo);
        double getOpen();
        void setOpen(double newOpen);
        double getHigh();
        void setHigh(double newHigh);
        double getLow();
        void setLow(double newLow);
        double getClose();
        void setClose(double newClose);
        unsigned long getVolume();
        void setVolume(unsigned long newVolume);
        void getCandleFromFile(FILE * fp);
        void show();
};


        candle::candle()// constructors
        {
          info=new char [100];
          strcpy(info,"No Info...");
          open=0;
          high=0;
          low=0;
          close=0;
          volume=0;
        }
        candle::candle(char * newinfo, double newopen, double newhigh, double newlow, double newclose, unsigned long newvolume)
        {
          int len=strlen(newinfo);
          info=new char [len+1];
          strncpy(info,newinfo,len);
          info[len+1]=0;
          open=newopen;
          high=newhigh;
          low=newlow;
          close=newclose;
          volume=newvolume;
        }
        candle::candle(const candle &x)
        {
          int len=strlen(x.info);
          info=new char [len+1];
          strncpy(info,x.info,len);
          info[len]=0;
          open=x.open;
          high=x.high;
          low=x.low;
          close=x.close;
          volume=x.volume;
        }

        candle::~candle()// destructor
        {
          if (info) delete []info;
        }
        char * candle::getInfo()
        {
             char * copyinfo;
             int len=strlen(info);
             copyinfo=new char[len+1];
             strncpy(copyinfo,info,len);
             copyinfo[len]=0;
             return copyinfo;
        }
        void candle::setInfo(char * newInfo)
        {
          if (info) delete[]info;
          int len=strlen(newInfo);
          info=new char [len+1];
          strncpy(info,newInfo,len);
          info[len]=0;
        }
        double candle::getOpen()
        {
               return open;
        }
        void candle::setOpen(double newOpen)
        {
             open=newOpen;
        }
        double candle::getHigh()
        {
               return high;
        }

        void candle::setHigh(double newHigh)
        {
             high=newHigh;
        }

        double candle::getLow()
        {
               return low;
        }

        void candle::setLow(double newLow)
        {
             low=newLow;
        }

        double candle::getClose()
        {
               return close;
        }

        void candle::setClose(double newClose)
        {
             close=newClose;
        }

        unsigned long candle::getVolume()
        {
               return volume;
        }

        void candle::setVolume(unsigned long newVolume)
        {
             volume=newVolume;
        }
        
        void candle::show()
        {
             cout<<"Candle:"<<endl;
             cout<<"Info="<<info<<endl;
             cout<<"Date="<<date<<endl;             
             cout<<"time="<<time<<endl;             
             cout<<"open="<<open<<endl;
             cout<<"high="<<high<<endl;
             cout<<"low="<<low<<endl;
             cout<<"close="<<close<<endl;
             cout<<"volume="<<volume<<endl;
        }

void candle::getCandleFromFile(FILE * fp)
{
     char buf[200];
     long n=0;
     char c=0;
     while (c!=',')
     {
           c=fgetc(fp);
           buf[n]=c;
           n++;
     }
     buf[n]=0;
     setInfo(buf);
     fscanf(fp,"%d,",&discr);
     fscanf(fp,"%ld,",&date);
     fscanf(fp,"%ld,",&time);
     fscanf(fp,"%lf,",&open);
     fscanf(fp,"%lf,",&high);
     fscanf(fp,"%lf,",&low);
     fscanf(fp,"%lf,",&close);
     fscanf(fp,"%ld,",&volume);
     fscanf(fp,"%ld\n",&openint);
}

int main(int argc, char *argv[])
{
    candle c1;
    candle c2("Bull",986,1110,980,1080,2300000);
    candle c3=c2;
    candle mas[1000];
    c2.show();
    c1.setInfo("Bear");
    cout<<"I set the info 'Bear'"<<endl;
    c1.show();
    cout<<"Testing how copy constructor works "<<endl;
    c3.show();
    cout<<"getInfo() returned:"<<c2.getInfo()<<endl;
    cout<<"getClose() returned:"<<c2.getClose()<<endl;
    cout<<"Testing setClose (setting close as 1000)..."<<endl;
    c2.setClose(1000);
    c2.show();
    FILE * fp=fopen("UX-3.13_130105_130206.txt","r");
    char s[200];
    fgets(s,198,fp);
    for (int i=0;i<1000;i++)
      mas[i].getCandleFromFile(fp);
    fclose(fp);
    for (int i=0;i<1000;i++)
    mas[i].show();

    system("PAUSE");
    return EXIT_SUCCESS;
}

// VIEW
// Candle:
// INFO=Bull
// open=986
// high=1110
// low=980
// close=1080
// volume=2300000

