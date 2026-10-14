uint32_t __fastcall
alias_class_for_symbol_set(c2_symbol *root,c2_bitset *pointees,c2_bitset *mask,c2_block *block)

{
  c2_alias_sym_info *pcVar1;
  c2_block *key;
  uint32_t uVar2;
  uint32_t uVar3;
  c2_bitset *pcVar4;
  c2_alias_class_cache *pcVar5;
  int iVar6;
  int iVar7;
  c2_alias_class_cache *pcVar8;
  int iVar9;
  uint32_t node;
  c2_block *key_00;
  c2_alias_class_cache *cached;
  bool several_nodes;
  
  if (pointees == (c2_bitset *)0x0) {
    pointees = symbol_overlap_alias_set(root,mask);
  }
  several_nodes = false;
  uVar2 = bitset_iter_next(pointees);
  node = 0xffffffff;
  if (uVar2 != 0xffffffff) {
    do {
      uVar3 = uVar2;
      if (node != 0xffffffff) {
        several_nodes = true;
        break;
      }
      uVar2 = bitset_iter_next((c2_bitset *)0x0);
      node = uVar3;
    } while (uVar2 != 0xffffffff);
    key = block;
    if (node != 0xffffffff) {
      pcVar1 = (root->u30).alias_info;
      pcVar5 = pcVar1->classes;
      for (pcVar8 = pcVar5; pcVar8 != (c2_alias_class_cache *)0x0; pcVar8 = pcVar8->next) {
        if (((!several_nodes) || (pcVar8->key == key)) &&
           (iVar6 = bitset_equal(pointees,pcVar8->pointees), iVar6 == 1)) {
          if (pcVar8 != (c2_alias_class_cache *)0x0) {
            bitset_free(pointees);
            return pcVar8->cls;
          }
          break;
        }
      }
      if ((several_nodes) ||
         (pcVar4 = alias_resolve_single_symbol_set((c2_symbol **)&mask,node),
         pcVar4 == (c2_bitset *)0x0)) {
        if (g_alias_class_count < 0x400) {
          uVar2 = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
        }
        else {
          uVar2 = 1;
        }
LAB_107529de:
        pcVar5 = alias_cache_node_new(uVar2,pointees,key,pcVar5);
        pcVar1->classes = pcVar5;
        return uVar2;
      }
      iVar6 = bitset_iter_next(pcVar4);
      iVar9 = -1;
      if (iVar6 != -1) {
        do {
          iVar7 = iVar6;
          if (iVar9 != -1) {
            several_nodes = true;
            break;
          }
          iVar6 = bitset_iter_next((c2_bitset *)0x0);
          several_nodes = false;
          iVar9 = iVar7;
        } while (iVar6 != -1);
        if (iVar9 != -1) {
          for (cached = (c2_alias_class_cache *)(mask[4].chunks)->bits;
              cached != (c2_alias_class_cache *)0x0; cached = cached->next) {
            if (((!several_nodes) || (cached->key == key)) &&
               (iVar6 = bitset_equal(pcVar4,cached->pointees), iVar6 == 1)) {
              if (cached != (c2_alias_class_cache *)0x0) {
                uVar2 = cached->cls;
                goto LAB_107529de;
              }
              break;
            }
          }
          uVar2 = g_alias_class_count;
          g_alias_class_count = g_alias_class_count + 1;
          pcVar8 = (c2_alias_class_cache *)(mask[4].chunks)->bits;
          key_00 = key;
          pcVar4 = bitset_clone(pcVar4);
          pcVar8 = alias_cache_node_new(uVar2,pcVar4,key_00,pcVar8);
          (mask[4].chunks)->bits = (uint32_t)pcVar8;
          goto LAB_107529de;
        }
      }
      return 2;
    }
  }
  return 2;
}

