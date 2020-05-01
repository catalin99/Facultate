DROP TABLE Customer;
DROP TABLE Reservation;
DROP TABLE City;
DROP TABLE Hotel;
DROP TABLE Payment;
DROP TABLE Bill;
DROP TABLE Rooms;
DROP TABLE Restaurant;
DROP TABLE Menu;
DROP TABLE Restaurant_tables;
/
create table City(
	city_id INT NOT NULL PRIMARY KEY,
	name VARCHAR2(15) NOT NULL,
	coordinates VARCHAR2(30) NOT NULL
)
/
create table Hotel(
	hotel_id INT NOT NULL PRIMARY KEY,
	city_id INT NOT NULL,
	name VARCHAR2(15) NOT NULL,
	coordinates VARCHAR(30) NOT NULL,
	address VARCHAR(15) NOT NULL,
	rating INT,
	no_floors INT,
	description VARCHAR2(30),
	room_facilities VARCHAR2(30),
	FOREIGN KEY(city_id) REFERENCES City(city_id)
)
/
create table Rooms(
	id INT NOT NULL PRIMARY KEY,
	hotel_id INT NOT NULL,
	capacity INT NOT NULL,
	price INT NOT NULL,
	facilities VARCHAR2(30),
	availability NUMBER(1,0),
	no_double_beds INT,
	no_single_beds INT,
	FOREIGN KEY (hotel_id) REFERENCES Hotel(hotel_id)
)
/
create table Reservation(
	reservation_id INT NOT NULL PRIMARY KEY,
	start_date DATE,
	end_date DATE,	
	Price INT NOT NULL,
	hotel_id INT,
	FOREIGN KEY (hotel_id) REFERENCES Hotel(hotel_id)
)
/
create table Customer(
	phone VARCHAR2(10) NOT NULL,
	email VARCHAR2(15) NOT NULL,
	name VARCHAR2(15) NOT NULL,
	cnp VARCHAR2(10) NOT NULL PRIMARY KEY,
	bank_account VARCHAR2(16),
	reservation_id INT NOT NULL,
	FOREIGN KEY (reservation_id) REFERENCES Reservation(reservation_id)
)
/
create table Payment(
	payment_method VARCHAR2(10),
	payment_date DATE,
	bank_account VARCHAR2(16)
)
/
create table Bill(
	amount INT NOT NULL,
	bill_id INT NOT NULL PRIMARY KEY,
	bill_date DATE,
	name VARCHAR2(15)
)
/
create table Restaurant(
	hotel_id INT NOT NULL,
	phone VARCHAR(10),
	FOREIGN KEY (hotel_id) REFERENCES Hotel(hotel_id)
)
/
create table Menu(
	hotel_id INT NOT NULL,
	name VARCHAR2(15),
	stock INT NOT NULL,
	price INT NOT NULL,
	weight INT,
	FOREIGN KEY (hotel_id) REFERENCES Hotel(hotel_id)
)
/
create table Restaurant_tables(
	hotel_id INT NOT NULL,
	disponibility NUMBER(1,0) NOT NULL,
	no_seats INT,
	FOREIGN KEY (hotel_id) REFERENCES Hotel(hotel_id)
)
/

insert into City (city_id, name, coordinates) values (1, 'Iasi', '47.1585,27.6014');
insert into Hotel (hotel_id, city_id, name, coordinates, address, rating, no_floors, description, room_facilities) 
    values (1, 1, 'Hotel Unirea', '47.1667,27.5805', 'Piata Unirii', 4, 12, 'Rooms are fitted with TVs', 'free-wifi, minibar');
    