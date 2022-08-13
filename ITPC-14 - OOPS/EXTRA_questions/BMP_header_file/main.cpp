#include<iostream>
#include<fstream>

using namespace std;

struct color{
    float r,g,b;  // r for red g for green and b for blue
    
    color(float r , float g , float b){
        this->r=r;
        this->g=g;
        this->b=b;
        
    }
    ~color();
    
};

class Image{
    
    int m_width;
    int m_height;
    color m_color[10000000];
    
public:
    Image(int width , int height){
        m_width=width;
        m_height=height;
    }

    ~Image();
    
    
    
    color get_color(int x, int y) const;
    void  set_color(const color &color , int x ,int y);
    void  Export(const char* path) const;
};

color Image::get_color(int x, int y) const{
    
    return m_color[y*m_width+x];
}

void Image::set_color(const color &color, int x, int y){
    m_color[y*m_width+x].r=color.r;
    m_color[y*m_width+x].g=color.g;
    m_color[y*m_width+x].b=color.b;
    
}

void Image::Export(const char *path) const{
    
    ofstream out(path);
    
    if(!out){
        cout<<"file cant be open"<<endl;
        return;
    }
    
    unsigned char bmpPad[3]={0,0,0};
    
    const int padding_amount = ((4-(m_width*3)%4)%4);
    
    const int fileHeaderSize = 14;
     
    const int informationHeaderSize = 40;
    
    const int fileSize= fileHeaderSize + informationHeaderSize + m_width*m_height*3 + padding_amount* m_width;
    
    unsigned char fileHeader[fileHeaderSize];
    
    fileHeader[0]='B';
    fileHeader[1]='M';
    
    fileHeader[2]=fileSize;
    fileHeader[3]=fileSize>>8;
    fileHeader[4]=fileSize>>16;
    fileHeader[5]=fileSize>>24;
    
    fileHeader[6]=0;
    fileHeader[7]=0;
    fileHeader[8]=0;
    fileHeader[9]=0;
    
    fileHeader[10]=fileHeaderSize+informationHeaderSize;
    fileHeader[11]=0;
    fileHeader[12]=0;
    fileHeader[13]=0;
    
    
    unsigned char informationHeader[informationHeaderSize];
    
    informationHeader[0]=informationHeaderSize;
    informationHeader[1]=0;
    informationHeader[2]=0;
    informationHeader[3]=0;
    
    informationHeader[4]=m_width;
    informationHeader[5]=m_width>>8;
    informationHeader[6]=m_width>>16;
    informationHeader[7]=m_width>>24;
    
    informationHeader[8]=m_height;
    informationHeader[9]=m_height>>8;
    informationHeader[10]=m_height>>16;
    informationHeader[11]=m_height>>24;
    
    informationHeader[12]=1;
    informationHeader[13]=0;
    
    informationHeader[14]=24;
    informationHeader[15]=0;

    // not signigicant pixels
    informationHeader[16]=0;
    informationHeader[17]=0;
    informationHeader[18]=0;
    informationHeader[19]=0;
    informationHeader[20]=0;
    informationHeader[21]=0;
    informationHeader[22]=0;
    informationHeader[23]=0;
    informationHeader[24]=0;
    informationHeader[25]=0;
    informationHeader[26]=0;
    informationHeader[27]=0;
    informationHeader[28]=0;
    informationHeader[29]=0;
    informationHeader[30]=0;
    informationHeader[31]=0;
    informationHeader[32]=0;
    informationHeader[33]=0;
    informationHeader[34]=0;
    informationHeader[35]=0;
    informationHeader[36]=0;
    informationHeader[37]=0;
    informationHeader[38]=0;
    informationHeader[39]=0;
    
    out.write((char*)fileHeader, fileHeaderSize);
    out.write((char*)informationHeader, informationHeaderSize);
    
    for(int i=0;i<m_height;i++){
        for(int j=0;j<m_width;j++){
            
            unsigned char r = (get_color(i,j).r * 255);
            unsigned char g = (get_color(i,j).g * 255);
            unsigned char b = (get_color(i,j).b * 255);
            
            unsigned char color[3]={b,g,r};
            
            out.write((char*)color,3);
            
        }
        out.write((char*)bmpPad,padding_amount);
    }
    out.close();
    
    cout<<"file is created succesfully"<<endl;
    
}

int main(){
    
    
    
    return 0;
}
