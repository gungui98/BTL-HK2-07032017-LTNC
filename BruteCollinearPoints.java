import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class BruteCollinearPoints {
    private int NumOfSegments;
    private LineSegment[] ls;
    public BruteCollinearPoints(Point[] points){
        ls = new LineSegment[1];
        if(points == null){
            throw new java.lang.IllegalArgumentException();
        }
        NumOfSegments = 0;
        for(int iter1=0;iter1<points.length-3;iter1++)
            for(int iter2=iter1+1;iter2<points.length-2;iter2++)
                for(int iter3=iter2+1;iter3<points.length-1;iter3++)
                    for(int iter4=iter3+1;iter4<points.length;iter4++){
                        if(points[iter1].slopeTo(points[iter2])==points[iter2].slopeTo(points[iter3]))
                            if(points[iter2].slopeTo(points[iter3])==points[iter3].slopeTo(points[iter4])) {
                                List<Point> list = new ArrayList<>();
                                list.add(points[iter1]);
                                list.add(points[iter2]);
                                list.add(points[iter3]);
                                list.add(points[iter4]);
                                Collections.sort(list);
                                if(ls.length == NumOfSegments){
                                    lsresize(2*ls.length);
                                }
                                ls[NumOfSegments++] = new LineSegment(list.get(0),list.get(list.size()-1));
                            }
                    }
    }// finds all line segments containing 4 points
    public int numberOfSegments(){
        return numberOfSegments();
    }        // the number of line segments
    public LineSegment[] segments(){
            return ls;
    }                // the line segments
    private void lsresize(int size){
        LineSegment[] templs = new LineSegment[size];
        for(int i=0;i<ls.length;i++){
            templs[i] = ls[i];
        }
        ls = templs;
    }
    public static void main(String[] args){
        Point[] points = new Point[10];
    }
}