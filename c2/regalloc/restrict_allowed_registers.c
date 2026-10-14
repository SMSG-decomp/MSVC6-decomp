void __fastcall restrict_allowed_registers(c2_live_range *range)

{
  byte bVar1;
  
  if ((range->flags5 & 0x80) == 0) {
    if (g_ebp_allocatable == 0) {
      bitset_clear(range->allowed,6);
    }
    bVar1 = range->flags6;
    if ((bVar1 & 2) != 0) {
      bitset_and(range->allowed,g_nonbyte_register_set);
      range->flags6 = bVar1 & 0xfd;
    }
    return;
  }
  bitset_and(range->allowed,g_byte_register_set);
  range->flags6 = range->flags6 | 2;
  return;
}

