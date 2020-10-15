#include <iostream>
#include <vector>


struct Pole
{
    std::vector<int> disks;
    char name;
};

void movedisk (Pole &source, Pole &dest)
{
    dest.disks.push_back(source.disks[source.disks.size()-1]);
    source.disks.erase(source.disks.begin()+(source.disks.size()-1), source.disks.end());
}

void playHanoi (int k, Pole &source, Pole &dest, Pole &temp)
{
    if (k==0)
        return;

    if (k==1)
    {
        std::cout << "Move one disk from " << source.name << " to " << dest.name << std::endl;
        movedisk (source,dest);
        //drawTowers(source,dest,temp);
        return;

    }

    playHanoi (k-1, source, temp, dest);
    playHanoi (1, source, dest, temp);
    playHanoi (k-1, temp, dest, source);


}


int main ()
{
    Pole A {{5,4,3,2,1},'A'}, B{{},'B'}, C {{},'C'};

    playHanoi (5,A,C,B);

}