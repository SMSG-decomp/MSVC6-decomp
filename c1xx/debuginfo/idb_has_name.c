int __thiscall idb_has_name(c1xx_idb *idb,char *name)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = name;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar2 = SigForPbCb(name,~uVar2 - 1,0);
  uVar2 = uVar2 & 0x3fff;
  if ((uVar2 < (idb->name_hash_bits).count << 5) &&
     (((idb->name_hash_bits).data[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) != 0)) {
    return 1;
  }
  return 0;
}

