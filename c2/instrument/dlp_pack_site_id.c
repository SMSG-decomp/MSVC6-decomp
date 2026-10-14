uint32_t __fastcall dlp_pack_site_id(uint32_t kind,uint32_t line,uint32_t id)

{
  uint uVar1;
  
  if (0x1000 < line) {
    line = 0;
  }
  uVar1 = (line & 0xfff) << 0x12 | id & 0x3ffff | kind << 0x1e;
  if (0x3ffff < id) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\dlp.c",0x2a);
  }
  return uVar1 ^ (uVar1 ^ id) & 0x3ffff;
}

