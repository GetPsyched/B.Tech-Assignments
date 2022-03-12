class foobar {
    public static void main(String[] args) {
        System.out.println("Details of some reading material :");
        ReadingMaterial r = new ReadingMaterial("xyz", 700); r.print();
        Book book = new Book("A","Mr.MS", "abc", 500); book.print();
        Magazine m = new Magazine("C Magazine", "Tech", "cde", 50); m.print();
        TechnicalJournal t = new TechnicalJournal("D Journal", "Tech", "computers", "ghj", 50); t.print();
        Novel n = new Novel("E Novel", "mno", "Fiction", "abd", 1000); n.print();
    }
}

class ReadingMaterial {
    String publication;
    int pages;
    public ReadingMaterial(String x, int n) {
        publication = x;
        pages = n;
    }
    public void print() {
        System.out.println("Details of reading material:");
        System.out.println("publication: " + this.publication);
        System.out.println("No. of pages: " + this.pages);
    }
}

class Book extends ReadingMaterial {
    public String title, author;
    public Book(String title, String author, String publication, int pages) {
        super(publication, pages);
        this.title = title;
        this.author = author;
    }
    public void print() {
        System.out.println("Details of book " + this.title);
        System.out.println("Title: " + this.title);
        System.out.println("Author: " + this.author);
        System.out.println("publication: " + this.publication);
        System.out.println("No. of pages: " + this.pages);
    }
}

class Novel extends Book {
    String genre;
    public Novel(String title, String author, String genre, String publication, int pages) {
        super(title, author, publication, pages);
        this.genre = genre;
    }
    public void print() {
        System.out.println("Details of the novel " + title);
        System.out.println("Name: "+ title);
        System.out.println("Author: "+ author);
        System.out.println("Genre: "+ genre);
        System.out.println("Publication: " + publication);
        System.out.println("No. of pages: " + pages);
    }
}

class Textbook extends Book {
    String subject;
    public Textbook(String subject, String title, String author, String publication, int pages) {
        super(title, author, publication, pages);
        this.subject = subject;
    }
    public void print() {
        System.out.println("Details of textbook " + this.title);
        System.out.println("Title: " + this.title);
        System.out.println("Author: " + this.author);
        System.out.println("Subject: " + this.subject);
        System.out.println("publication: " + this.publication);
        System.out.println("No. of pages: " + this.pages);
    }
}

class Journal extends ReadingMaterial {
    public String name;
    public Journal(String name,String publication, int pages) {
        super(publication, pages);
        this.name = name;
    }
    public void print() {
        System.out.println("Details of journal " + this.name);
        System.out.println("Title: " + this.name);
        System.out.println("publication: " + this.publication);
        System.out.println("No. of pages: " + this.pages);
    }
}

class Magazine extends ReadingMaterial {
    public String name, topic;
    public Magazine(String name, String topic, String publication, int pages) {
        super(publication, pages);
        this.name = name;
        this.topic = topic;
    }
    public void print() {
        System.out.println("Details of the Magazine " + name);
        System.out.println("Name: "+ name);
        System.out.println("Topic: " + topic);
        System.out.println("Publication: " + publication);
        System.out.println("No. of pages: " + pages);
    }
}

class TechnicalJournal extends Journal {
    public String subject, topic;
    public TechnicalJournal(String name, String subject, String topic, String publication, int pages) {
        super(name, publication, pages);
        this.subject = subject;
        this.topic = topic;
    }
    public void print() {
        System.out.println("Details of the journal " + name);
        System.out.println("Name: "+ name);
        System.out.println("Name: "+ subject);
        System.out.println("Topic: " + topic);
        System.out.println("Publication: " + publication);
        System.out.println("No. of pages: " + pages);
    }
}
