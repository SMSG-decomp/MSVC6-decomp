void __fastcall ide_feedback_write(int fd,void *buf,uint32_t count)

{
  fflush((FILE *)(_iob_exref + fd * 0x20));
  _write(fd,buf,count);
  return;
}

