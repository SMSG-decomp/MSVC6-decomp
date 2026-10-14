c2_switch_case * __fastcall switch_add_case(c2_tuple *sw,c2_tuple *label,int32_t hi,int32_t lo)

{
  c2_switch_case *cell;
  c2_switch_case *old_cases;
  
  cell = (c2_switch_case *)node_alloc('\x1d');
  old_cases = (sw->u24).cases;
  (sw->u24).cases = cell;
  cell->lo = lo;
  cell->next = old_cases;
  cell->label = label;
  cell->hi = hi;
  cell->owner = sw;
  label_add_ref(label,(c2_node *)cell);
  return cell;
}

