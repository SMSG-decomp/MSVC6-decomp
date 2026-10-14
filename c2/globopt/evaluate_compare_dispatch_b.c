uint32_t * __fastcall evaluate_compare_dispatch_b(uint32_t op)

{
  switch(op) {
  case 0x17e:
    return g_cmp_ops_contradicting_eq;
  case 0x17f:
    return g_cmp_ops_contradicting_ne;
  case 0x180:
    return g_cmp_ops_contradicting_lt;
  case 0x181:
    return g_cmp_ops_contradicting_gt;
  case 0x182:
    return g_cmp_ops_contradicting_le;
  case 0x183:
    return g_cmp_ops_contradicting_ge;
  }
}

