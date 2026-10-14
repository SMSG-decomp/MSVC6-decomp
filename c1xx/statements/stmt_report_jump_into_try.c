void __cdecl stmt_report_jump_into_try(c1_symbol *label)

{
  char cVar1;
  
  if ((label->detail).cls == (c1_class_record *)0x13) {
    cVar1 = 'c';
  }
  else if ((label->detail).cls == (c1_class_record *)0x14) {
    cVar1 = 'g';
  }
  else {
    cVar1 = '\x06';
  }
  if ((g_compile_flags_c8 & 0x10000) == 0) {
    if (cVar1 == '\x06') {
      diag_error(0x2c1,0x53,label);
    }
    else {
      diag_error(0x2c1,0x4c,cVar1);
    }
  }
  if ((label->flags2 & 4) != 0) {
    label->flags5 = label->flags5 | 4;
  }
  return;
}

