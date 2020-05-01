package shopcart;

public class Product {
	private String name;
	private float price;
	private int barcode;
	Product(String name,float price,int barcode)
	{
		this.name=name;
		this.price=price;
		this.barcode=barcode;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public float getPrice() {
		return price;
	}
	public void setPrice(float price) {
		this.price = price;
	}
	public int getBarcode() {
		return barcode;
	}
	public void setBarcode(int barcode) {
		this.barcode = barcode;
	}
	
}
