int __fastcall count_allocatable_int_registers(c2_function *fn)

{
  if ((fn->flags & 0x10) != 0) {
    g_ebp_allocatable = 1;
    return 7;
  }
  g_ebp_allocatable = 0;
  return 6;
}

