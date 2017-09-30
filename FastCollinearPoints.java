import java.awt.*;
import java.util.*;
import java.util.List;

/**
 * Created by GUNGUI on 28/9/2017.
 */
public class FastCollinearPoints {
    private int NumOfSegments;
    private ArrayList<LineSegment> ls;
    public FastCollinearPoints(Point[] points){
        boolean b;
        ls = new ArrayList<>();
        Point[] iter = points.clone();
        List<Point> listOfPoint;
        for (Point i :iter){
            NumOfSegments =0;
            Arrays.sort(points,i.slopeOrder());
            for(int j=0;j<points.length-3;j++){
                if(i.slopeTo(points[j]) == i.slopeTo(points[j+1]))
                    if(i.slopeTo(points[j]) == i.slopeTo(points[j+2])) {
                            b=false;
                            listOfPoint = new ArrayList<>();
                            listOfPoint.add(i);
                            for(int k=j;k<j+3;k++)
                                listOfPoint.add(points[k]);
                            Collections.sort(listOfPoint);
                            LineSegment line = new LineSegment(listOfPoint.get(0),listOfPoint.get(listOfPoint.size()-1));
                            for(LineSegment k :ls){
                                if(k.toString().compareTo(line.toString())==0)
                                    b = true;
                            }
                            if(b)
                                continue;
                            ls.add(line);
                        }
            }
        }
    }  // finds all line segments containing 4 or more points
    public int numberOfSegments(){
        return 0;
    }       // the number of line segments

    public LineSegment[] segments(){
        return ls.toArray(new LineSegment[ls.size()]);
    }          // the line segments
    public static void main(String[] args){
        // read the n points from a file
        In in = new In(args[0]);
        int n = in.readInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
        }

        // draw the points
        edu.princeton.cs.algs4.StdDraw.setPenColor(Color.RED);
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32000);
        StdDraw.setYscale(0, 32000);


        // print and draw the line segments
        // FastCollinearPoints collinear = new FastCollinearPoints(points);
        FastCollinearPoints Bcollinear = new FastCollinearPoints(points);

        for (LineSegment segment : Bcollinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        LineSegment line = new LineSegment(new Point(32000,32000),new Point(0,0));
        line.draw();
        StdDraw.show();
    }
}