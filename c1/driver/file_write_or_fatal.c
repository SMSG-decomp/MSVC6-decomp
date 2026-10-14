void __cdecl file_write_or_fatal(FILE *f)

{
  char zeros [512];
  
  fflush(f);
  if ((f->_flag & 0x20) != 0) {
    _write(f->_file,zeros,0x200);
    diag_fatal_file_errno(0x55,0x153,(char *)0x0);
  }
  return;
}

