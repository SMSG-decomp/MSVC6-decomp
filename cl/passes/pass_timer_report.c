void __cdecl pass_timer_report(char *program)

{
  int n;
  uint ms;
  int secs;
  char digits [8];
  
  if (g_preprocess_only == 0) {
    ftime(&g_pass_end_time);
    msg_write(1,"time(%s)=",program);
    secs = g_pass_end_time.time - g_pass_start_time.time;
    ms = (uint)g_pass_end_time.millitm - (uint)g_pass_start_time.millitm;
    if ((int)ms < 0) {
      ms = ms + 1000;
      secs = secs + -1;
    }
    strcpy(digits,"00");
    n = uint_to_string(ms,digits + 2,10);
    msg_write(1,"%d.%ss\n",secs,&stack0xfffffff3 + n);
  }
  return;
}

