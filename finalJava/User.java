abstract class User {
  // Orizo ta pedia tis klasis
  private String username;
  private String pword;
  private String name;
  private String lastName;
  private String email;
  private String phone;

  // Orizo ton constructor
  // ("usernamel","password","onoma","epitheto","emali","tilefono")
  public User(String username, String pword, String name, String lastName, String email, String phone) {
    this.username = username;
    this.name = name;
    this.lastName = lastName;
    this.pword = pword;
    this.email = email;
    this.phone = phone;
  }

  // Iperfortono tin toString()
  public String toString() {
    return new String("Username :" + username + "\nPasswsord : " + pword + "\nName : " + name + "\nLast Name : "
        + lastName + "\nEmail : " + email + "\nPhone Number : " + phone + "\n");
  }

  // Setters/Getters
  public void setUsername(String username) {
    this.username = username;
  }

  public void setPassword(String pword) {
    this.pword = pword;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public void setPhone(String phone) {
    this.phone = phone;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setLastName(String lastName) {
    this.lastName = lastName;
  }

  public String getUsername() {
    return username;
  }

  public String getName() {
    return name;
  }

  public String getLastName() {
    return lastName;
  }

  public String getPhone() {
    return phone;
  }

  public String getEmail() {
    return email;
  }

}
