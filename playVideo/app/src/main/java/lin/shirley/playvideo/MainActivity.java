package lin.shirley.playvideo;

import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.MediaController;

public class MainActivity extends AppCompatActivity {
    private FullScreenViedoView mVideoView;
    private ImageButton mImageButton;
    private ImageView mImageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().hide(); //隱藏標題
        getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN); //隱藏狀態

        mVideoView = (FullScreenViedoView) this.findViewById(R.id.videoView);
        mImageButton = (ImageButton) this.findViewById(R.id.imageButton);
        mImageView= (ImageView) findViewById(R.id.imageView);

        MediaController mc = new MediaController(this);
        mVideoView.requestFocus();
        mc.setVisibility(View.INVISIBLE);
        mVideoView.setMediaController(mc);
        mVideoView.setVideoURI(Uri.parse("android.resource://" + getPackageName() + "/" + R.raw.one));
        mImageButton.setImageResource(R.drawable.logo);
        mImageButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mVideoView.start();
                mImageButton.setVisibility(View.INVISIBLE);
                mImageView.setVisibility(View.INVISIBLE);
            }
        });
        mImageButton.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                mImageButton.setImageResource(R.drawable.big);
                return false;
            }
        });
        mVideoView.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion(MediaPlayer mediaPlayer) {
                mImageButton.setVisibility(View.VISIBLE);
                mImageView.setVisibility(View.VISIBLE);
            }
        });



    }
}
