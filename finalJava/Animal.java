import java.util.ArrayList;

//Orizo enum gia to eidos tou zoou
enum AnimalType {
  DOG, CAT, BIRD
}

public class Animal {

  // Orizo ta pedia tou kathe animal
  private String id;
  private String name;
  private int age;
  private String description;
  private AnimalType type;
  private MedicalRecord medicalRecord;

  // Orizo ton constructor ("id","onoma",ilikia,"perigrafi",AnimalType)
  public Animal(String id, String name, int age, String description, AnimalType type) {
    this.id = id;
    this.name = name;
    this.age = age;
    this.description = description;
    this.type = type;
    this.medicalRecord = new MedicalRecord();
  }

  // Setters/Gettesr ton private pedion
  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getDescription() {
    return description;
  }

  public void setDescription(String description) {
    this.description = description;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }

  public AnimalType getType() {
    return type;
  }

  public void setType(AnimalType type) {
    this.type = type;
  }

  public MedicalRecord getMedicalRecord() {
    return medicalRecord;
  }
  // Den exw setMedicalRecord giati mono oi xeirourgoi mporoun na vazoun nea
  // xeirourgeia

  // Iperfortono tin toString()
  public String toString() {
    return new String("Animal { " + "\nID :" + id + "\nName :" + name + "\nAge : " + age + "\nDescription : "
        + description + "\nAnimal Type" + type + "}\n");
  }

}
