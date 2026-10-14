void __cdecl _chkstk(uint size)

{
  char *probe;
  undefined4 unaff_retaddr;
  
  probe = &stack0x00000004;
  for (; 0xfff < size; size = size - 0x1000) {
    probe = probe + -0x1000;
  }
  *(undefined4 *)(probe + (-4 - size)) = unaff_retaddr;
  return;
}

