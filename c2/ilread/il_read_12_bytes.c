uint32_t * il_read_12_bytes(uint32_t *out)

{
  uint32_t local_c;
  uint32_t local_8;
  uint32_t local_4;
  
  il_read_bytes(0xc,(char *)&local_c);
  *out = local_c;
  out[1] = local_8;
  out[2] = local_4;
  return out;
}

