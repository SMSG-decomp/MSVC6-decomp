uint32_t * __fastcall evaluate_compare_dispatch_a(uint32_t op)

{
  switch(op) {
  case 0x17e:
    return g_cmp_ops_implying_eq;
  case 0x17f:
    return g_cmp_ops_implying_ne;
  case 0x180:
    return g_cmp_ops_implying_lt;
  case 0x181:
    return g_cmp_ops_implying_gt;
  case 0x182:
    return g_cmp_ops_implying_le;
  case 0x183:
    return g_cmp_ops_implying_ge;
  }
}

