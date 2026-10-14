int __fastcall cv_put_name(uint8_t *out,char *name)

{
  char cVar1;
  uint uVar2;
  uint32_t len;
  char *pcVar3;
  
  if (name == (char *)0x0) {
    len = 0;
  }
  else {
    uVar2 = 0xffffffff;
    pcVar3 = name;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    len = ~uVar2 - 1;
    if ((0xff < (int)len) && (g_opt_warn4786 != 0)) {
      warning(1,0x312,name,0xff);
      if (g_il_wide_type_index != 0) {
        cv_truncate_name_with_hash(out,name,len);
        return 0x100;
      }
      *out = 0xff;
      strncpy((char *)(out + 1),name,0xff);
      out[0x101] = '\0';
      return 0x100;
    }
  }
  *out = (uint8_t)len;
  strncpy((char *)(out + 1),name,len);
  out[len + 2] = '\0';
  return len + 1;
}

