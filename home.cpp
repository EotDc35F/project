#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    QSettings movie("mot","prj");
    int size=movie.beginReadArray("movie");
    for(int i=0;i<size;i++)
    {
        mv tmp;
        movie.setArrayIndex(i);
        tmp.director=movie.value("director").toString();
        tmp.language=movie.value("language").toString();
        tmp.release_year=movie.value("release_year").toString();
        tmp.stars=movie.value("stars").toString();
        tmp.valence=movie.value("valence").toString();
        tmp.name=movie.value("name").toString();
        tmp.genre=movie.value("genre").toString();
        tmp.imdb=movie.value("imdb").toString();
        movies.append(tmp);
    }
    movie.endArray();
}

home::~home()
{
    delete ui;
}

void home::save_to_setting()
{
    QSettings movie("mot","prj");
    movie.beginWriteArray("movie");
    for(int i=0;i<movies.size();i++)
    {
        movie.setArrayIndex(i);
        movie.setValue("director",movies.at(i).director);
        movie.setValue("language",movies.at(i).language);
        movie.setValue("release_year",movies.at(i).release_year);
        movie.setValue("stars",movies.at(i).stars);
        movie.setValue("valence",movies.at(i).valence);
        movie.setValue("name",movies.at(i).name);
        movie.setValue("genre",movies.at(i).genre);
        movie.setValue("imdb",movies.at(i).imdb);
    }
    movie.endArray();
}
