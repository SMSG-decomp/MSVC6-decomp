void __thiscall declarator_set_flags54_bit5(c1_declarator *d,char value)

{
  d->flags54 = (value & 1U) << 5 | d->flags54 & 0xdf;
  return;
}

