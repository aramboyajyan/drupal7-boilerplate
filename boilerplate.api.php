<?php

/**
 * @file
 * Hooks provided by the Boilerplate module.
 * Include here instructions for integration with your custom module.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * The API implementation examples below were taken from the hook_post_action
 * module.
 */

/**
 * Gets called after an entity has been inserted/updated/deleted to database.
 *
 * @param $entity
 *   An entity object
 * @param string $entity
 *   An string containing entity type name
 * @param string $op
 *   An string containing the operating that's taking place (insert/update/delete)
 *
 * @see hook_entity_postinsert()
 * @see hook_entity_postupdate()
 * @see hook_entity_postdelete()
 * @ingroup entity_api_hooks
 */
function hook_entity_postsave($entity, $entity_type, $op) {
  list($id) = entity_extract_ids($entity_type, $entity);
  watchdog('boilerplate_test', 'The @operation entity @entity_type id is @id from @function.', array(
    '@id' => $id,
    '@function' => __FUNCTION__,
    '@operation' => t($operation . 'd'),
    '@entity_type' => $entity_type,
  ));
}

/**
 * Gets called after an entity has been inserted to database.
 *
 * @param $entity
 *   An entity object
 * @param string $entity
 *   An string containing entity type name
 *
 * @see hook_entity_postsave()
 * @see hook_entity_postupdate()
 * @see hook_entity_postdelete()
 * @ingroup entity_api_hooks
 */
function hook_entity_postinsert($entity, $entity_type) {
  list($id) = entity_extract_ids($entity_type, $entity);
  watchdog('boilerplate_test', 'The inserted entity @entity_type id is @id from @function.', array(
    '@id' => $id,
    '@function' => __FUNCTION__,
    '@entity_type' => $entity_type,
  ));
}

/**
 * Gets called after an entity has been updated in database.
 *
 * @param $entity
 *   An entity object
 * @param string $entity
 *   An string containing entity type name
 *
 * @see hook_entity_postsave()
 * @see hook_entity_postinsert()
 * @see hook_entity_postdelete()
 * @ingroup entity_api_hooks
 */
function hook_entity_postupdate($entity, $entity_type) {
  list($id) = entity_extract_ids($entity_type, $entity);
  watchdog('boilerplate_test', 'The updated entity @entity_type id is @id from @function.', array(
    '@id' => $id,
    '@function' => __FUNCTION__,
    '@entity_type' => $entity_type,
  ));
}

/**
 * Gets called after an entity has been deleted from database.
 *
 * @param $entity
 *   An entity object
 * @param string $entity
 *   An string containing entity type name
 *
 * @see hook_entity_postsave()
 * @see hook_entity_postinsert()
 * @see hook_entity_postupdate()
 * @ingroup entity_api_hooks
 */
function hook_entity_postdelete($entity, $entity_type) {
  list($id) = entity_extract_ids($entity_type, $entity);
  watchdog('boilerplate_test', 'The deleted entity @entity_type id is @id from @function.', array(
    '@id' => $id,
    '@function' => __FUNCTION__,
    '@entity_type' => $entity_type,
  ));
}

/**
 * Gets called after a node has been inserted/updated/deleted to database.
 *
 * @param $node
 *   A node object
 * @param string $op
 *   An string containing the operating that's taking place (insert/update/delete)
 *
 * @see hook_node_postinsert()
 * @see hook_node_postupdate()
 * @see hook_node_postdelete()
 * @ingroup node_api_hooks
 */
function hook_node_postsave($node, $op) {
  watchdog('boilerplate_test', 'The @operation node @node_type id is @nid from @function.', array(
    '@nid' => $node->nid,
    '@function' => __FUNCTION__,
    '@node_type' => $node->type,
    '@operation' => t($op . 'd'),
  ));
}

/**
 * Gets called after a node has been inserted to database.
 *
 * @param $node
 *   A node object
 *
 * @see hook_node_postsave()
 * @see hook_node_postupdate()
 * @see hook_node_postdelete()
 * @ingroup node_api_hooks
 */
function hook_node_postinsert($node) {
  watchdog('boilerplate_test', 'The inserted node @node_type id is @nid from @function.', array(
    '@nid' => $node->nid,
    '@function' => __FUNCTION__,
    '@node_type' => $node->type,
  ));
}

/**
 * Gets called after a node has been updated to database.
 *
 * @param $node
 *   A node object
 *
 * @see hook_node_postsave()
 * @see hook_node_postinsert()
 * @see hook_node_postdelete()
 * @ingroup node_api_hooks
 */
function hook_node_postupdate($node) {
  watchdog('boilerplate_test', 'The updated node @node_type id is @nid from @function.', array(
    '@nid' => $node->nid,
    '@function' => __FUNCTION__,
    '@node_type' => $node->type,
  ));
}

/**
 * Gets called after a node has been deleted from database.
 *
 * @param $node
 *   A node object
 *
 * @see hook_node_postsave()
 * @see hook_node_postinsert()
 * @see hook_node_postupdate()
 * @ingroup node_api_hooks
 */
function hook_node_postdelete($node) {
  watchdog('boilerplate_test', 'The deleted node @node_type id is @nid from @function.', array(
    '@nid' => $node->nid,
    '@function' => __FUNCTION__,
    '@node_type' => $node->type,
  ));
}