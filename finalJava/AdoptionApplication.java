import java.util.Date;

//Enum gia tin katastasi tis kathe aitisis
enum ApplicationStatus {
  PENDING, APPROVED, REJECTED
}

public class AdoptionApplication {
  // Orizo ta pedia kathe aitisis : ton adopter pou kanei tin aitisi, to zwo pou
  // afora, tin imerominia, kai ti kastastasi tis aitisis
  private Adopter adopter;
  private Animal animal;
  private Date date;
  private ApplicationStatus applicationStatus;

  // Orizo ton constructor (Adopter,Animal,Date,ApplicationStatus)
  public AdoptionApplication(Adopter adopter, Animal animal, Date date, ApplicationStatus applicationStatus) {
    this.adopter = adopter;
    this.animal = animal;
    this.date = date;
    this.applicationStatus = applicationStatus;
  }

  // Setters/Getters ton private pedion
  public Adopter getAdopter() {
    return adopter;
  }

  public void setAdopter(Adopter adopter) {
    this.adopter = adopter;
  }

  public Animal getAnimal() {
    return animal;
  }

  public void setAnimal(Animal animal) {
    this.animal = animal;
  }

  public Date getDate() {
    return date;
  }

  public void setDate(Date date) {
    this.date = date;
  }

  public ApplicationStatus getApplicationStatus() {
    return applicationStatus;
  }

  public void setApplicationStatus(ApplicationStatus applicationStatus) {
    this.applicationStatus = applicationStatus;
  }

  // Iperfortono tin toString()
  public String toString() {
    return new String("Application { " + "\nAdopter :" + adopter + "\nAnimal : " + animal + "\nDate : " + date
        + "\nApplidation Status " + applicationStatus + "}\n");
  }

}
