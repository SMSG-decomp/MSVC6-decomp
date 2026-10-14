int __cdecl pragma_check_pack_value(int n)

{
  switch(n) {
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x10:
    break;
  default:
    diag_warning(1,0x56);
    n = g_pack_stack->top->packing;
  }
  return n;
}

