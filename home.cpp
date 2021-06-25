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
    save_to_setting();
    destroy_items();
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
    destroy_items();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(movies->size());
    for(int i=0;i<movies->size();i++)
    {
        QTableWidgetItem* director =new QTableWidgetItem;
        QTableWidgetItem* stars = new QTableWidgetItem;
        QTableWidgetItem*release_year =new QTableWidgetItem;
        QTableWidgetItem* language = new QTableWidgetItem;
        QTableWidgetItem* genre = new QTableWidgetItem;
        QTableWidgetItem* name = new QTableWidgetItem;
        QTableWidgetItem*valence =new QTableWidgetItem;
        QTableWidgetItem* imdb = new QTableWidgetItem;
        director->setTextAlignment(Qt::AlignCenter);
        director->setText(movies->at(i).director);
        stars->setText(movies->at(i).stars);
        stars->setTextAlignment(Qt::AlignCenter);
        release_year->setText(movies->at(i).release_year);
         release_year->setTextAlignment(Qt::AlignCenter);
        language->setText(movies->at(i).language);
         language->setTextAlignment(Qt::AlignCenter);
        genre->setText(movies->at(i).genre);
         genre->setTextAlignment(Qt::AlignCenter);
        name->setText(movies->at(i).name);
         name->setTextAlignment(Qt::AlignCenter);
        valence->setText(movies->at(i).valence);
         valence->setTextAlignment(Qt::AlignCenter);
        imdb->setText(movies->at(i).imdb);
        imdb->setTextAlignment(Qt::AlignCenter);
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
QString combo_g="All";

void home::comb_g(QString s)
{
    combo_g=s;
    if(s=="All")
       {
        load_table(&movies);
        return;
    }
    QList<mv> nmovies;
    for(int i=0;i<movies.size();i++)
    {
      if(movies.at(i).genre.contains(s))
      {
          nmovies.append(movies.at(i));
      }
    }
    load_table(&nmovies);
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



void home::on_add_clicked()
{
    add=new Add(this,&movies,this,&combo_g);
       this->hide();
        add->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
       add->show();
}

void home::on_edit_clicked()
{  QString name=this->ui->ledit->text();
    bool find=false;
    int index=0;
    for(int i=0;i<movies.size();i++)
    {
        if(movies.at(i).name==name)
        {
          find=true;
           index=i;
           break;
        }
    }
    if(!find)
       {
        QMessageBox::warning(this,"Edit","There is no movie with this name!\nPlease try again");
        ui->ledit->clear();
        return;
}
   edit=new class edit(this,&movies,this,&name,index,&combo_g);
    ui->ledit->clear();
   this->hide();
   edit->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
   edit->show();
}


void home::on_remove_clicked()
{    bool find=false;
    QString r=this->ui->lremove->text();
    for(int i=0;i<movies.size();i++)
    {
        if(movies.at(i).name==r)
        {
            movies.removeAt(i);
            QMessageBox::information(this,"Remove","Successfully removed");
            comb_g(combo_g);
            find=true;
            this->ui->lremove->clear();
            break;
        }
    }
     if(!find)
     {
         QMessageBox::warning(this,"Remove","There is no movie with this name!\nPlease try again");
         this->ui->lremove->clear();
     }
}

void home::on_comboBox_currentTextChanged(const QString &arg1)
{
    comb_g(arg1);
}

void home::on_pushButton_clicked()
{
    ui->lremove->clear();
}

void home::on_lineEdit_textChanged(const QString &arg1)
{   if(arg1=="")
    {
        load_table(&movies);
        return;
    }
    QList<mv> nmovies;
    for(int i=0;i<movies.size();i++)
    {
        if(movies.at(i).name.startsWith(arg1,Qt::CaseInsensitive))
        {
            nmovies.append(movies.at(i));
            continue;
        }
        if(movies.at(i).director.startsWith(arg1,Qt::CaseInsensitive))
        {
            nmovies.append(movies.at(i));
            continue;
        }
        if(movies.at(i).stars.contains(arg1))
        {
            nmovies.append(movies.at(i));
            continue;
        }
        if(movies.at(i).language.startsWith(arg1,Qt::CaseInsensitive))
        {
            nmovies.append(movies.at(i));
            continue;
        }
        if(movies.at(i).release_year.startsWith(arg1,Qt::CaseInsensitive))
        {
            nmovies.append(movies.at(i));
            continue;
        }
        if(movies.at(i).genre.contains(arg1,Qt::CaseInsensitive))
        {
            nmovies.append(movies.at(i));
            continue;
        }
        if(movies.at(i).imdb.startsWith(arg1,Qt::CaseInsensitive))
        {
            nmovies.append(movies.at(i));
            continue;
        }
    }
    load_table(&nmovies);
}




void home::on_reserve_clicked()
{
    reserve=new class reserve(this,&movies,this);
       this->hide();
        reserve->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
       reserve->show();
}
