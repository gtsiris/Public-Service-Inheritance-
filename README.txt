���������:
�� ��������� ������������ ��� ���������� ���� ������� �������� ���������.
������, ���� �� ���������� �� ��� ����� ������ �������� ��� ������ ��� ������.
���� �������� ��� ������ ���� ����� ���������� ���� ������ ��� �������.
����-����, �� ��������� ���������� ������������� �� ������ ���� ���� ��� �������� �� ��� ����� �� ��� ����� ��������.
���� ������� ���� � ���������� ��� �������� ������� ��� ������ ���� ��� ���� ����� ����������� ��� �������.
���� ���� ���������� ��� ��� ����� �������� ��������� �� ���� ��� ������, �������� ��'����.
���� ���������� ��� ������� ��� ������� ������� ������ �������������� ��� ��������� �� �������.
��� ��� ������ ����� ����� � ������� ���� ���������� ����� � ������������� ��� ��������� �� ���� ���� ��� ��������� �� ���������� ��� ������.
�� ������� ������� �� ������� ���� ���������������� ������� ����������� ���.
������� ��� ������ ���� �� ����:
  ���� ���������� ������ �������� ��� �������.
  ����������� ����� �� ��� ���������� �������������.
  ����-����, �� ��������� ������������� ��� ��� ��� ����������� � ������� ��� ���������� ��� �������.
  �� ����� ���������� �������������, �� ������� ��������� �� ���� ����� ������������ ��� ����������.
  ���� ���������� ������������ ���� ����� ��� �������� �� ������� ����� ��'�����.
  ����������� ����� �� ��� ���������� �������������.
  ������ � ���������� ����� ��� �������.
  �� � ���������� ���� ���� �����, ���� ����� �������� �� ���� ��� ������� ��� ��������.
  �� �� ������� ����� ������, ���� � ���������� ������� ���� ���� ������� ��� ������ ����� �� ����� � ����� ���.
  �� ������� ���� ���������� ��� ���� ��������� ����� (4� ������������) ������� �� �������� ���������� ��� �������������� ��� �� ������� ��� ����� ������� �� ������.
  ��������� ��� �� ���� ����� ������������� ��� �� ���������� ��������������� ���������� ������ ���� �������.
  �� ����� �������� ��������� ��� �������������� ������� �� ������ ������� ��� ���� ���������� ���� ��-����� �������� ��� ������.
  ���� �������������� ���������� ������� ��� �� ������� ��� �� ���� ��� �������.
  ���� ������� ��� ������� � ������ �� ������������� ��� ��� ���� �������� ��� ������ ��� ����� �� ���� �'����.
  ���� �� ������ ������ ��� �������, ���� �� �������������� ���������� ������������� ��� ���� �������� �������� ��� �� ������.
  �� ��������� ���������� ��� �������.

������������:
���������� �������������:
g++ -o Public_Service Public_Service.cpp class_Building.cpp class_Entrance.cpp class_Floor.cpp class_Ground.cpp class_Level.cpp class_Lift.cpp class_Limited_Space.cpp class_Office.cpp class_Unlimited_Space.cpp class_Visitor.cpp class_Visitor_List.cpp

�������!! ���� ������ ������� ����� extended initializer list ��� ������������� ��� C+11 (����������� ������� �� ������� ����������� ��� ������ ��� ���������).
��� ��� ���� ���� ������������ ��� �� �������� ��� warnings:
class_Building.cpp: In constructor 'Building::Building(const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int& ':
class_Building.cpp:9:2: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11
 f{Floor(1, capacity, floor_capacity, ground_capacity, office_capacity), Floor(2, capacity, floor_capacity, ground_capacity, office_capacity),
  ^
class_Floor.cpp: In constructor 'Floor::Floor(const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&)':
class_Floor.cpp:9:2: warning: extended initializer lists only available with -std=c++11 or -std=gnu++11
 o{Office(1, floor_capacity, office_capacity), Office(2, floor_capacity, office_capacity),

��������:
���������� ���������: ./Public_Service 9 2 1 1 2 1 1
...

��� �� ���������� �� ��������� �� ������ �� ������ ��� ��� ������ ������� �� ���� �������� �� ��� ���� �����:
N, Nf, Ng, No, Nl, K, L
����: � = ������� ������������ ���������� ��� �������
      Nf = ������� ������������ ���������� ��� �������
      Ng = ������� ������������ ���������� ��� ��������
      No = ������� ������������ ���������� ��� ��������
      Nl = ������� ������������ ���������� ��� �������
      K = ������� ��������� ����������
      L = ������� ������ ����������� ��� ������� ��� �� �����������