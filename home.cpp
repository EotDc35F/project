#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    save_to_list();
    load_table( &movies);

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

void home::save_to_list()
{
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

void home::load_table(QList<mv>*movies)
{
    ui->tableWidget->setRowCount(movies->size());
    for(int i=0;i<movies->size();i++)
    {
        QTableWidgetItem* director = nullptr;new QTableWidgetItem;
        QTableWidgetItem* stars = nullptr;new QTableWidgetItem;
        QTableWidgetItem*release_year = nullptr;new QTableWidgetItem;
        QTableWidgetItem* language = nullptr;new QTableWidgetItem;
        QTableWidgetItem* genre = nullptr;new QTableWidgetItem;
        QTableWidgetItem* name = nullptr;new QTableWidgetItem;
        QTableWidgetItem*valence = nullptr;new QTableWidgetItem;
        QTableWidgetItem* imdb = nullptr;new QTableWidgetItem;
        director->setText(movies->at(i).director);
        stars->setText(movies->at(i).stars);
        release_year->setText(movies->at(i).release_year);
        language->setText(movies->at(i).language);
        genre->setText(movies->at(i).genre);
        name->setText(movies->at(i).name);
        valence->setText(movies->at(i).valence);
        imdb->setText(movies->at(i).imdb);
        ui->tableWidget->setItem(i,0,name);
        ui->tableWidget->setItem(i,1,director);
        ui->tableWidget->setItem(i,2,stars);
        ui->tableWidget->setItem(i,3,release_year);
        ui->tableWidget->setItem(i,4,language);
        ui->tableWidget->setItem(i,5,genre);
        ui->tableWidget->setItem(i,6,imdb);
        ui->tableWidget->setItem(i,7,valence);
        names.append(name);
        directors.append(director);
        qstars.append(stars);
        release_years.append(release_year);
        languages.append(language);
        genres.append(genre);
        imdbs.append(imdb);
        valences.append(valence);



    }
}

void home::destroy_items()
{
    for(int i=0;i<names.size();i++)
    {
        delete names[i];
        delete languages[i];
        delete directors[i];
        delete qstars[i];
        delete imdbs[i];
        delete valences[i];
        delete genres[i];
        delete release_years[i];
    }
     names.clear();
     languages.clear();
     directors.clear();
     qstars.clear();
     imdbs.clear();
     valences.clear();
     genres.clear();
    release_years.clear();

}



void home::on_close_clicked()
{
    save_to_setting();
    this->close();
}
