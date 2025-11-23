---
Created: 2024-01-25T13:33
Class: Comp1537 - WebDev
Reviewed: false
tags:
  - CSS
  - HTML
---
# Transforms

- animation-and-transforms/transforms is a good example of class & id selector mixing

# Animations

- @keyframes is how to tell the page you’re making an animation
- animation property is how you call the animation
    
    - infinite tag is how you make it loop
# Layouts

- Generally going to have 3
- Lots of extra work, but required due to number of potential devices and resolutions
- **Design for mobile first**

### Liquid Layout


### Responsive Web Development(RWD)

- Queries all the media
- @media queries the device based on the media
    - can create ranges that change the site based on how its being viewed
- Good: One site, one download set, same design everywhere
- Bad: TERRIBLE for bandwidth, since it downloads everything, even if you don’t use it. BAD load times

### Adaptive Web Development(AWD)

- Server checks what device is connecting, and sends items accordingly
- Good: Efficient, each device type gets its own template
- Bad: Requires a LOT of templates


- display: inline - only takes up the amount of space it needs, like `<span>`

- display: block - Takes up the most amount of space they can. Nothing can be on the same line as them, like `<p>`

- float - which side it sticks to, left or right.

- clear - if something can touch it on that side, left or right. If you select the side, it will move anything on that side down a line.

## display: grid;

Make containers, then start putting things inside of them.

READ THE SITES ON THE SLIDE FROM THE LECTURE - slide

height: 100vh; = 100% Viewport Width

Percentage says it plans to use 100% of what the PARENT is, so if the parent is set to to 50%, and the child is 50%, the child is now only 25% instead of 50%

vw/vh = useful at top level, sets it to the width and height of the device looking at it.

grid-template-column & grid-template-rows NEEDS TO EQUAL 100%

all child items of the container(with the display: grid property!) should have grid-column and grid-rows property. Starts with NON-ZERO. STARTS AT 1.

grid-column:1 / span 4;

means

grid-column: start_column / span end_column;

End column is INCLUSIVE

You can have grids within grids

## Responsive Grid

You can set this with a media call to adjust based on width and height

Best practices

- Create multiple layouts with media queries
- DESIGN FOR MOBILE FIRST
- USE PERCENTAGES