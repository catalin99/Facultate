package gui;

import java.awt.*;

public class NodeDisplay implements Display {
    private int coordX, coordY, radius;
    private Color color;
    public NodeDisplay(int coordX, int coordY, int radius, Color color) {
        this.coordX = coordX;
        this.coordY = coordY;
        this.radius = radius;
        this.color = color;
    }

    public int getCoordX() {
        return coordX;
    }

    public int getCoordY() {
        return coordY;
    }

    public int getRadius() {
        return radius;
    }

    public Color getColor() {
        return color;
    }

    public void setCoordX(int coordX) {
        this.coordX = coordX;
    }

    public void setCoordY(int coordY) {
        this.coordY = coordY;
    }

    public void setRadius(int radius) {
        this.radius = radius;
    }

    public void setColor(Color color) {
        this.color = color;
    }
}
