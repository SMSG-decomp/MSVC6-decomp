void __cdecl __alloca_probe(uint32_t size)

{
  uint8_t *probe;
  undefined4 unaff_retaddr;
  
  probe = &stack0x00000004;
  for (; 0xfff < size; size = size - 0x1000) {
    probe = probe + -0x1000;
  }
  *(undefined4 *)(probe + (-4 - size)) = unaff_retaddr;
  return;
}

