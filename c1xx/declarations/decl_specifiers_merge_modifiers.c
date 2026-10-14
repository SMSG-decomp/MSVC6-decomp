char __cdecl decl_specifiers_merge_modifiers(byte *spec,uint mods)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  
  bVar1 = (mods & 8) != 0;
  if (bVar1) {
    *spec = *spec | 8;
  }
  bVar2 = (mods & 0x10) != 0;
  if (bVar2) {
    *spec = *spec | 0x10;
  }
  bVar3 = (mods & 0x20) != 0;
  if (bVar3) {
    *spec = *spec | 0x20;
  }
  bVar4 = (mods & 0x40) != 0;
  if (bVar4) {
    *spec = *spec | 0x40;
  }
  bVar5 = (mods & 0x8000) != 0;
  if (bVar5) {
    spec[1] = spec[1] | 0x80;
  }
  bVar6 = (mods & 0x400000) != 0;
  if (bVar6) {
    spec[2] = spec[2] | 0x40;
  }
  bVar7 = (mods & 0x80) != 0;
  if (bVar7) {
    *spec = *spec | 0x80;
  }
  bVar8 = (mods & 0x100) != 0;
  if (bVar8) {
    spec[1] = spec[1] | 1;
  }
  bVar9 = (mods & 0x200) != 0;
  if (bVar9) {
    spec[1] = spec[1] | 2;
  }
  bVar10 = (mods & 0x400) != 0;
  if (bVar10) {
    spec[1] = spec[1] | 4;
  }
  bVar11 = (mods & 0x4000000) != 0;
  if (bVar11) {
    spec[3] = spec[3] | 4;
  }
  bVar12 = (mods & 0x8000000) != 0;
  if (bVar12) {
    spec[3] = spec[3] | 8;
  }
  bVar13 = (mods & 0x1000) != 0;
  if (bVar13) {
    spec[1] = spec[1] | 0x10;
  }
  bVar14 = (mods & 0x2000) != 0;
  if (bVar14) {
    spec[1] = spec[1] | 0x20;
  }
  bVar15 = (mods & 0x20000) != 0;
  if (bVar15) {
    spec[2] = spec[2] | 2;
  }
  bVar16 = (mods & 0x10000) != 0;
  if (bVar16) {
    spec[2] = spec[2] | 1;
  }
  bVar16 = bVar16 || (bVar15 ||
                     (bVar14 ||
                     (bVar13 ||
                     (bVar12 ||
                     (bVar11 ||
                     (bVar10 ||
                     (bVar9 || (bVar8 || (bVar7 || (bVar6 || (bVar5 || (bVar4 || (bVar3 || (bVar2 ||
                                                                                           bVar1))))
                                                   ))))))))));
  if ((mods & 0x40000) == 0) {
    if ((mods & 0x80000) == 0) goto LAB_1044d943;
    spec[2] = spec[2] & 0xfb | 8;
  }
  else {
    spec[2] = spec[2] & 0xf7 | 4;
  }
  bVar16 = true;
LAB_1044d943:
  if ((mods & 0x10000000) != 0) {
    spec[3] = spec[3] | 0x10;
    bVar16 = true;
  }
  return bVar16;
}

