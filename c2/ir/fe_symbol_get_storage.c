c2_symbol * __fastcall fe_symbol_get_storage(c2_fe_symbol *fs)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  uint uVar3;
  byte kind;
  uint32_t size;
  
  if (fs->storage_sym != (c2_symbol *)0x0) {
    return fs->storage_sym;
  }
  switch(fs->cls) {
  case '\x01':
    uVar3 = fs->storage;
    switch(uVar3 >> 4 & 7) {
    case 1:
      goto override_jmp_1073314a_case_1;
    case 2:
      kind = ((uVar3 & 0x780) == 0x200) + 7;
      break;
    case 3:
      kind = 5;
      break;
    case 4:
      uVar3 = uVar3 >> 7 & 0xf;
      if (uVar3 != 0) {
        if (uVar3 < 3) {
          kind = 7;
          break;
        }
        if (uVar3 == 4) {
          kind = 8;
          break;
        }
      }
      kind = 9;
      break;
    case 5:
      kind = (byte)(fs->attrs >> 4) & 2 | 5;
    }
    break;
  case '\x02':
override_jmp_1073314a_case_1:
    kind = 4;
    break;
  case '\x03':
    kind = 0xb;
    break;
  case '\x04':
    kind = 10;
  }
  pcVar2 = symbol_alloc(kind);
  uVar1 = fs->cls;
  fs->storage_sym = pcVar2;
  pcVar2->fe = fs;
  if (uVar1 != '\x03') {
    if (uVar1 == '\x04') {
      size = fs->refcount;
    }
    else {
      size = fs->size;
    }
    uVar3 = il_type_to_c2_type((byte)fs->storage & 0xf,size);
    pcVar2->type = (uint16_t)uVar3;
    pcVar2->size = size;
    pcVar2->cls = kind;
    pcVar2->storage = pcVar2;
    return pcVar2;
  }
  pcVar2->type = 0x1004;
  pcVar2->size = 4;
  pcVar2->cls = kind;
  pcVar2->storage = pcVar2;
  return pcVar2;
}

