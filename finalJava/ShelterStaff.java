import java.util.Date;
import java.util.InputMismatchException;

public class ShelterStaff extends User {
  // Orizo ton constructor
  public ShelterStaff(String username, String pword, String name, String lastName, String email, String phone) {
    super(username, pword, name, lastName, email, phone);
  }

  // Orizo methodo gia na ftiaxnv neous ktiniatrous
  public Vet registerNewVet(String username, String pword, String name, String lastName, String email, String phone) {
    return new Vet(username, pword, name, lastName, email, phone);
  }

  // Orizo methodo gia na ftiaxnvw nea zoa
  public Animal registerNewAnimal(String id, String name, AnimalType type, int age, String description) {
    return new Animal(id, name, age, description, type);
  }

  // orizo methodo gia na ftaixnw nees diloseis
  public AdoptionApplication registerApplication(Adopter adopter, Animal animal, Date date, ApplicationStatus status) {
    if (animal != null && adopter != null) {
      return new AdoptionApplication(adopter, animal, date, status);
    } else {
      throw new IllegalArgumentException("Something wrong was typed");
    }
  }

  // Orizo methodo gia na allazo to status mias dilosis
  public void changeApplicationStatus(AdoptionApplication application, ApplicationStatus newStatus) {
    if (application != null) {
      application.setApplicationStatus(newStatus);
    } else {
      throw new IllegalArgumentException("Application doesn't exist");
    }
  }

  // Orizo methodo gia na allakso ton adopter mias dilosis
  public void changeAdopter(AdoptionApplication application, Adopter adopter) {
    if (adopter != null && application != null) {
      application.setAdopter(adopter);
    } else {
      throw new IllegalArgumentException("Application or user doesn't exist");
    }
  }

  // Orizo methodo gia na allakso to zwo mias dilosis
  public void changeAnimal(AdoptionApplication application, Animal animal) {
    if (application != null && animal != null) {
      application.setAnimal(animal);
    } else {
      throw new IllegalArgumentException("Application or animal doesn't exist");
    }
  }

  // Orizo methodo gia na alakso tin imerominia mias dilosis
  public void changeDate(AdoptionApplication application, Date date) {
    if (application != null) {
      application.setDate(date);
    } else {
      throw new IllegalArgumentException("Application doesn't exist");
    }
  }

}
