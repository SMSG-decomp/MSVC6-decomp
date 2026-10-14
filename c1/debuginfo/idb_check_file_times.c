int __fastcall idb_check_file_times(c1_idb_state *idb)

{
  Map_DWORD_DWORD *map;
  ISet *set;
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  time_t tVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_3c;
  char *local_38;
  uint uStack_34;
  uint local_28;
  _stat file_stat;
  
  map = &idb->file_times;
  uVar8 = 0xffffffff;
LAB_10646ce6:
  do {
    do {
      uVar2 = (idb->file_times).rgd.itMac;
      uVar8 = uVar8 + 1;
      if (uVar2 <= uVar8) {
        return 1;
      }
      while (((idb->file_times).isetPresent.rgw.itMac << 5 <= uVar8 ||
             (((idb->file_times).isetPresent.rgw.rgt[uVar8 >> 5] & 1 << ((byte)uVar8 & 0x1f)) == 0))
            ) {
        uVar8 = uVar8 + 1;
        if (uVar2 <= uVar8) {
          return 1;
        }
      }
      uVar3 = (idb->file_times).rgr.rgt[uVar8];
      uVar2 = (map->rgd).rgt[uVar8];
      local_28 = uVar8;
      iVar5 = (*idb->name_map->vtbl->getName)(idb->name_map,uVar2,&local_38);
      if (iVar5 == 0) {
        return 0;
      }
      file_stat.st_mtime = -1;
      iVar5 = stat(local_38,&file_stat);
    } while ((iVar5 == 0) && (uVar3 == file_stat.st_mtime));
    iVar5 = (*idb->vtbl->idb_invalidate)(idb);
    tVar4 = file_stat.st_mtime;
    if (iVar5 == 0) {
      return 0;
    }
    if (file_stat.st_mtime != -1) {
      uVar8 = (idb->file_times).rgd.itMac;
      uVar6 = (uVar2 & 0xffff) % uVar8;
      uVar7 = 0xffffffff;
      uStack_34 = uVar6;
      do {
        iVar5 = iset_contains(&(idb->file_times).isetPresent,uVar6);
        if (iVar5 == 0) {
          if (uVar7 == 0xffffffff) {
            uVar7 = uVar6;
          }
          iVar5 = iset_contains(&(idb->file_times).isetDeleted,uVar6);
          if (iVar5 == 0) break;
        }
        else if ((map->rgd).rgt[uVar6] == uVar2) {
          (idb->file_times).rgr.rgt[uVar6] = tVar4;
          uVar8 = local_28;
          goto LAB_10646ce6;
        }
        uVar6 = -(uint)(uVar6 + 1 < uVar8) & uVar6 + 1;
      } while (uVar6 != uStack_34);
      if (uVar7 < (idb->file_times).isetDeleted.rgw.itMac << 5) {
        puVar1 = (idb->file_times).isetDeleted.rgw.rgt + (uVar7 >> 5);
        *puVar1 = *puVar1 & ~(1 << ((byte)uVar7 & 0x1f));
      }
      set = &(idb->file_times).isetPresent;
      iVar5 = iset_ensure_room(set,uVar7);
      if (iVar5 != 0) {
        puVar1 = (set->rgw).rgt + (uVar7 >> 5);
        *puVar1 = *puVar1 | 1 << ((byte)uVar7 & 0x1f);
      }
      (map->rgd).rgt[uVar7] = uVar2;
      (idb->file_times).rgr.rgt[uVar7] = tVar4;
      map_grow_2(map);
      uVar8 = local_28;
      goto LAB_10646ce6;
    }
    uStack_34 = (idb->file_times).rgd.itMac;
    uVar6 = (uVar2 & 0xffff) % uStack_34;
    local_3c = 0xffffffff;
    uVar7 = uVar6;
    do {
      iVar5 = iset_contains(&(idb->file_times).isetPresent,uVar7);
      if (iVar5 == 0) {
        if (local_3c == 0xffffffff) {
          local_3c = uVar7;
        }
        iVar5 = iset_contains(&(idb->file_times).isetDeleted,uVar7);
        if (iVar5 == 0) break;
      }
      else if ((map->rgd).rgt[uVar7] == uVar2) {
        iset_remove(&(idb->file_times).isetPresent,uVar7);
        iset_add(&(idb->file_times).isetDeleted,uVar7);
        puVar1 = &(idb->file_times).cdr;
        *puVar1 = *puVar1 - 1;
        break;
      }
      uVar7 = -(uint)(uVar7 + 1 < uStack_34) & uVar7 + 1;
    } while (uVar7 != uVar6);
  } while( true );
}

