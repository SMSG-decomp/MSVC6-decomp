void __thiscall declarator_set_flags56_bit1(c1_declarator *d,char value)

{
  d->flags56 = (value & 1U) << 1 | d->flags56 & 0xfd;
  return;
}

