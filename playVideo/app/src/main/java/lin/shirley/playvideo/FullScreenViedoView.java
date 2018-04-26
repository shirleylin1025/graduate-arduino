package lin.shirley.playvideo;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.VideoView;

/**
 * Created by linyuxuan on 2018/3/20.
 */

public class FullScreenViedoView extends VideoView {

    public FullScreenViedoView(Context context) {
        super(context);
    }

    public FullScreenViedoView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public FullScreenViedoView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        int width = getDefaultSize(0, widthMeasureSpec);
        int height = getDefaultSize(0, heightMeasureSpec);
        setMeasuredDimension(width, height);
    }
}
