#include <iostream>
#include <vector>

using namespace std;

class Artist
{
protected:
    string artistName;

public:
    Artist(string name) : artistName(name) {}

    virtual string getType() = 0;

    string getName()
    {
        return artistName;
    }
};

class Musician : public Artist
{
public:
    Musician(string name) : Artist(name) {}

    string getType() override
    {
        return "Musician";
    }
};

class Band : public Artist
{
private:
    vector<Musician> musicians;

public:
    Band(string name) : Artist(name) {}

    void addMusician(Musician musician)
    {
        musicians.push_back(musician);
    }

    string getType() override
    {
        return "Band";
    }
};

class Song
{
private:
    Artist *performer;
    Artist *writer;
    string title;

public:
    Song(Artist *perf, Artist *writ, string songTitle) : performer(perf), writer(writ), title(songTitle) {}

    Artist *getPerformer()
    {
        return performer;
    }
    Artist *getWriter()
    {
        return writer;
    }
    string getTitle()
    {
        return title;
    }
};

class Track
{
private:
    Song song;
    int bitrate;
    int duration;
    Track *nextTrack;
    Track *prevTrack;

public:
    Track(Song s, int bit, int dur) : song(s), bitrate(bit), duration(dur), nextTrack(nullptr), prevTrack(nullptr) {}

    Song getSong()
    {
        return song;
    }
    int getBitrate()
    {
        return bitrate;
    }
    int getDuration()
    {
        return duration;
    }
    Track *getNextTrack()
    {
        return nextTrack;
    }
    Track *getPrevTrack()
    {
        return prevTrack;
    }

    void setNextTrack(Track *next)
    {
        nextTrack = next;
    }
    void setPrevTrack(Track *prev)
    {
        prevTrack = prev;
    }
};

class Album
{
private:
    vector<Track> tracks;

public:
    void addTrack(Track track)
    {
        tracks.push_back(track);
    }

    vector<Track> getTracks()
    {
        return tracks;
    }
};

int main()
{
    Musician rohail("Rohail Hyatt");
    Musician shahzad("Shahzad Hasan");
    Musician nusrat("Nusrat Hussain");
    Musician salman("Salman Ahmad");

    Band vitalSigns("Vital Signs");
    vitalSigns.addMusician(rohail);
    vitalSigns.addMusician(shahzad);
    vitalSigns.addMusician(nusrat);
    vitalSigns.addMusician(salman);

    Song dilDilPakistan(&rohail, &shahzad, "Dil Dil Pakistan");
    Song aitebar(&salman, &nusrat, "Aitebar");

    Track track1(dilDilPakistan, 320, 180);
    Track track2(aitebar, 256, 210);

    track1.setNextTrack(&track2);
    track2.setPrevTrack(&track1);

    Album humTum;
    humTum.addTrack(track1);
    humTum.addTrack(track2);

    cout << "Tracks in the album 'Hum Tum':" << endl
         << endl;
    for (int i = 0; i < humTum.getTracks().size(); i++)
    {
        Track track = humTum.getTracks()[i];
        cout << "Title: " << track.getSong().getTitle() << "\nPerformer: " << track.getSong().getPerformer()->getName();

        if (track.getSong().getWriter() != nullptr)
        {
            cout << "\nWriter: " << track.getSong().getWriter()->getName();
        }
        cout << endl
             << endl;
    }

    return 0;
}