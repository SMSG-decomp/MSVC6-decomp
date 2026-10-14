void __fastcall pch_fixup_tree_list_object(c1xx_obj_104bcbcc *obj)

{
  pch_mark_object_links((int)obj);
  pch_relocate_slot_once(&g_pch_image,(uint *)(obj + 4));
  pch_relocate_tree((c1_node *)obj[4].vtbl);
  return;
}

