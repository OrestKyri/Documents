//Orizo tin klasi Adopter 
public class Adopter extends User {
  // Arxikopoio to pedia diefthinsis,perigrafis kai tis ilikias tou tou adopter
  private String address;
  private String description;
  private int age;

  // Orizo ton constructor
  // ("username","kodikos","onoma","epitheto","email","tilefono","dietfthinsi","perigrafi",ilikia)
  public Adopter(String username, String pword, String name, String lastName, String email, String phone,
      String address,
      String description, int age) {
    // Kalo ton constructor tis klasis User
    super(username, pword, name, lastName, email, phone);
    this.address = address;
    this.description = description;
    this.age = age;
  }

  // Setters/Getters ton private pedion
  public void setAdress(String address) {
    this.address = address;
  }

  public void setDescprition(String description) {
    this.description = description;
  }

  public void setAge(int age) {
    this.age = age;
  }

  public String getAddress() {
    return address;
  }

  public String getDescription() {
    return description;
  }

  public int getAge() {
    return age;
  }

  // Iperfortono tin toString
  public String toString() {
    return new String("Adopter { " + super.toString() + "\nAddress : " + address + "\nDescription : " + description
        + "\n Age : " + age + " }");
  }
}
