import java.util.ArrayList;
import java.util.Objects;
import java.io.*;

//Apo ti stigmi pou tha iparxei mono ena shelter den iparxei logos na dimiourgiso pote ena antikeimeno shelter ara ola ta kano static
public class Shelter implements Serializable {
  // Plirofories shelter
  private static String name = "Gatia kai Skilia";
  private static String address = "Peiraias";
  private static String phone = "22222222";

  public static void shelterInfoSerialization() {
    try {
      FileOutputStream file = new FileOutputStream("Info.ser");
      ObjectOutputStream out = new ObjectOutputStream(file);
      out.writeObject(name);
      out.writeObject(address);
      out.writeObject(phone);
      out.close();
    } catch (IOException ex) {
      System.out.println("System IO exception caught");
    }
  }

  public static void shelterInfoDeserialization() {
    try {
      FileInputStream file = new FileINputStream("Info.ser");
      ObjectInputStream in = new ObjectInputStream(file);

      // Daiavazo apo to arxeio ta pedia pou exo apothikefsei
      name = (String) in.readObject();
      address = (String) in.readObject();
      phone = (String) in.readObject();
      file.close();
      in.close();
    } catch (IOException ex) {
      System.out.println("No file found");
    }
  }

  // Arxikopoio tis listes me tous xristes,ta zoa kai tis aitiseis
  public static ArrayList<User> users = new ArrayList<User>();

  static {

    users.add(new Adopter("mfilip", "mfx", "Michael", "Filippakis", "mfilip@unipi.gr", "22222223"));
    users.add(new Adopter("amenixtas", "javamono", "Apostolos", "Menixtas", "amenixtas@unipi.gr", "22222232"));
    users.add(new Adopter("meliones", "basi3.5", "Apostolos", "Milionis", "ameliones@unipi.gr", "32222222"));
    users.add(new Vet("alexios", "dem", "Alexandros", "Armeniakos", "armeniakos@unipi.", "111111"));
    users.add(new Vet("takis", "takaros", "Mitsaras", "Takaros", "dtakis@unipi.gr", "22222222"));
    users.add(new ShelterStaff("orestios", "orest", "Orestis", "Kyri", "orestkyri@gmail.com", "6947626657"));
  }

  public static void userSerialization() {

    try {
      FileOutputStream file = new FileOutputStream("Users.ser");
      ObjectOutputStream out = new ObjectOutputStream(file);
      out.writeObject(users);
      out.close();
    } catch (IOException ex) {
      System.out.println("System IO exception  caught");
    }
  }

  public static void userDeserialization() {
    try {
      FileInputStream file = new FileInputStream("Users.ser");
      ObjectInputStream in = new ObjectInputStream(file);
      users = (ArrayList<User>) in.readObject();
      in.close();
    } catch (IOException ex) {
      System.out.println("File not found");
    }
  }

  public static ArrayList<Animal> animals = new ArrayList<Animal>();

  static {

    animals.add("terror139", "Tromos", 8, "Pitbull", DOG);
    animals.add("katastrofeas999", "Katastrofeas", 9, "Mia katastrofi", CAT);
    animals.add("prigkipisa1010", "Prigkipisa", 10, "Cane Corso", DOG);
    animals.add("polly555", "Polly", 5, "Ena pouli", BIRD);
  }

  public static void animalSerialization() {

    try {
      FileOutputStream file = new FileOutputStream("Animals.ser");
      ObjectOutputStream out = new ObjectOutputStream(file);
      out.writeObject(animals);
      out.close();
    } catch (IOException ex) {
      System.out.println("System IO exception caught ");
    }
  }

  public static void animalDeserialization() {
    try {
      FileInputStream file = new FileInputStream("Animals.ser");
      ObjectInputStream in = new ObjectInputStream(file);
      animals = (ArrayList<Animal>) in.readObject();
      in.close();
    } catch (IOException ex) {
      System.out.println("File not found");
    }
  }

  public static ArrayList<AdoptionApplication> applications = new ArrayList<AdoptionApplication>();

  public static void applicationSerialization() {
    try {
      FileOutputStream file = new FileOutputStream("Applications.ser");
      ObjectOutputStream out = new ObjectOutputStream(file);
      out.writeObject(applications);
      out.close();
    } catch (IOException ex) {
      System.out.println("System IO exception caught");

    }
  }

  public static void applicationDeserialization() {
    try {
      FileInputStream file = new FileInputStream("Applications.ser");
      ObjectInputStream in = new ObjectInputStream(file);
      applications = (ArrayList<AdoptionApplication>) in.readObject();
      in.close();
    } catch (IOException ex) {
      System.out.println("File not found");
    }
  }

  public String toString() {
    return new String(
        "Shelter { " + "\nName : " + name + "\nAddress : " + address + "\nPhone number : " + phone + "}\n");
  }

  // Getters ton static pedion
  public static String getShelterName() {
    return name;
  }

  public static String getShelterAddress() {
    return address;
  }

  public static String getShelterPhone() {
    return phone;
  }

  // Methodos gia na prostheso user
  public static void addUser(User newUser) {
    for (int i = 0; i < users.size(); i++) {
      if (Objects.equals(users.get(i).getUsername(), newUser.getUsername())) {
        System.out.println("User already exists");
      } else {
        users.add(newUser);
      }
    }
  }

  // Methodos gia na svino users
  public static void deleteUser(String username) {
    for (int i = 0; i < users.size(); i++) {
      // Sigkrino ta username gia na vro ton xristi
      if (Objects.equals(users.get(i).getUsername(), username)) {
        users.remove(i);
        i--;// Meiono to i giati i lista mikrine kata 1
      } else {
        continue;
      }
    }
  }

  public static void addAnimal(Animal newAnimal) {
    for (int i = 0; i < animals.size(); i++) {
      if (Objects.equals(animals.get(i).getId(), newAnimal.getId())) {
        System.out.println("Animal already exists");
      } else {
        animals.add(newAnimal);
      }
    }

  }

  // Methodos gia na sbino zoa
  public static void deleteAnimal(String animalID) {
    for (int i = 0; i < animals.size(); i++) {
      if (Objects.equals(animals.get(i).getId, animalID)) {
        animals.remove(i);
        i--;
      } else {
        continue;
      }
    }
  }

  // Mehtodos gia na kano nees aitiseis
  public static void newApplication(AdoptionApplication newApplication) {
    for (int i = 0; i < applications.size(); i++) {
      if (Objects.equals(applications.get(i).getAdopter().getUsername(), newApplication.getAdopter().getUsername())
          && applications.get(i).getStatus == PENDING) {
        printf("A candidate can only have one active application");
      } else {
        applications.add(newApplication);
      }
    }
  }

  // Methodos gia na allazo to status mias atitisis
  public static void changeApplicationStatus(Adopter candidate, ApplicationStatus newStatus) {
    for (int i = 0; i < applications.size(); i++) {
      if (Objects.equals(applications.get(i).getAdopter().getUsername(), candidate.getUsername())) {
        applications.set(i, newStatus);
      } else {
        continue;
      }
    }
  }

}
