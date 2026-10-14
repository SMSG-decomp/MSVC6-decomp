int __cdecl fold_float_store_result_3(c1_u8 *a,c1_u8 *b,c1_u8 *out)

{
  int iVar1;
  float10 value;
  
  if (_adjust_fdiv == 0) {
    value = *(float10 *)a / *(float10 *)b;
  }
  else {
    value = (float10)_adj_fdiv_r();
  }
  if (((*(ushort *)(a + 10) | *(ushort *)(b + 10)) & 2) == 0) {
    if (((*(ushort *)(a + 10) | *(ushort *)(b + 10)) & 8) == 0) {
      out[10] = '\x04';
      out[0xb] = '\0';
    }
    else {
      out[10] = '\b';
      out[0xb] = '\0';
    }
  }
  else {
    out[10] = '\n';
    out[0xb] = '\0';
  }
  iVar1 = fpu_store_constant_rounded(value,(float10 *)out);
  return iVar1;
}

