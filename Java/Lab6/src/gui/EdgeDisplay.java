package gui;

import java.awt.*;

public class EdgeDisplay implements Display{
    private int startX, startY, endX, endY;
    private Color color;
    private int stroke;

    public EdgeDisplay(int startX, int startY, int endX, int endY, Color color, int stroke) {
        this.startX = startX;
        this.startY = startY;
        this.endX = endX;
        this.endY = endY;
        this.color = color;
        this.stroke = stroke;
    }

    public int getStartX() {
        return startX;
    }

    public int getStartY() {
        return startY;
    }

    public int getEndX() {
        return endX;
    }

    public int getEndY() {
        return endY;
    }

    public Color getColor() {
        return color;
    }

    public int getStroke() {
        return stroke;
    }

    public void setStartX(int startX) {
        this.startX = startX;
    }

    public void setStartY(int startY) {
        this.startY = startY;
    }

    public void setEndX(int endX) {
        this.endX = endX;
    }

    public void setEndY(int endY) {
        this.endY = endY;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public void setStroke(int stroke) {
        this.stroke = stroke;
    }
}
