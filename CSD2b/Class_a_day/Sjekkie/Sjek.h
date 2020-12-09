class Sjek{
public:
  Sjek();
  ~Sjek();
  void setSjekType(std::string sjekType);
  std::string getSjekType();
private:
  std::string sjekType;
};
