## What Is The Web?

- Protocols:
    - HTTP, or HTTPS if encrypted
        - Hyper Text Transfer Protocol
    - Web Server receives requests, sends content(HTML, CSS, Javascript)
        - Web Server is a computer that runs Web Server Software (e.g. Apache)
        - Can be dedicated or shared (on a network/cloud)
        - Usually has plugin modules for running languages, such as Dynamic Content Generation(DCG)
    - Web Browser makes requests, accepts content
        - Browser is an application that renders the content (Text, images, video, etc)
- Three Tiered Web Architecture
    - Client tier
        - Sends HTTP Request to Business
    - Business Logic Tier
        - Sends Request Data to Database
        - Sends HTML page to Client
    - Database Tier
        - Sends Data back to Business
- Mobile platform is the **default** platform
    - Mobile == Smart Phones, Tablets, etc
- Cloud Computing is norm
    - Instagram, Dropbox, Azure, Drive, etc
    - SSAS(Software as a Service) - Office 365, Adobe, etc.
- Internet of Things (IoT)
    - Connection of all things to the internet
        - Cars, Fridge, Dryers, Toasters, Home climate control/alarm, etc
- Privacy issues are forefront atm
- Legal/Ethical/Copyright issues have also become prominent
    - Who owns the rights to a YouTube video of video game gameplay?
    - Who’s responsible for an app user posting ads for illegal activity?

## HTML - The Common Web Dialect

- Web browsers can play/display content
    - Text/Images/Audio/Video/etc.
- Has a standard structured markup language
    - HyperText Markup Language (HTML)
- Two helper types
    - Cascading Style Sheets (CSS)
    - JavaScript (JS)
- Uses **tags**
    - Beginning tag, end tag, and all the stuff in the middle
    - Tags are made of Less Than (<) Greater Than (>) and forward slash (/)
    - The begin and end tag together form an **element**
        - All elements **must** have a begin tag and end tag
            - <p> </p>
        - There is a shorthand for “Empty element”
            
            - <br/>
            - Only allowed for certain **Void Elements**:
            
            [http://www.w3.org/html/wg/drafts/html/master/syntax.html#void-elements](http://www.w3.org/html/wg/drafts/html/master/syntax.html#void-elements)
            
- Attributes goes in the **START** tag
    - `<html lang=”en”>`
    - Attributes do not have an implied order
    - Attribute name is followed by **equals, begin quote, the value,** then the **end code**
    - Attributes can use single or double quotes
        
        ```JavaScript
        <p id=”a123” class=’shaded’>Some Text!</p>
        ```
        
- HTML allows for comments are well
    
    ```JavaScript
    <!--
    	This section is a comment block!
    -->
    ```
    
- For characters that are part of the HTML syntax, we use **entities**
    
    - Entity syntax is Ampersand, same of entity, semicolon
    
    ```JavaScript
    &name_of_entity;
    ```
    
    - Common entities:
    
    ```JavaScript
    &lt; &gt; &quot; &apos; &amp; &copy;
    ```
    
    - Can also use Unicode values, but is less common
- All HTML files contain exactly **ONE** root element: html
- The HTML element contains **two** child elements: head, body

## Elements

- The root element is the **html** element
    - html element has the _lang_ attribute, set to “en” for English
- The **head** element is the first child of html
    - Contains all the non-rendered elements
    - Contains several children of its own
        - _title, link, meta, script, style_
        - title: Used to display text in the browser title bar
        - link: used to provide metadata, eg: character set used
            - use to be used for SEO, no longer acknowledged by search engines
        - style: allows for style information to be embedded
            - should be avoided -one sheet can be linked to by multiple documents, thereby it cuts down the amount of time it takes to download all the content on the page.
- The **body** element is the second child of html
    - Contains all **visible** elements
    - Common body elements:
        - Heading elements (h1 - h6)
        - p - for paragraph
        - br - for creating newline or space between sections
        - ul - for creating Unordered Lists (bullet points)
        - ol - Ordered Lists (numbered, 1 2 3 4, i ii iii iv, etc)
        - dl - Definition Lists (Term and definition pairs. Not used much, if at all)
    - Paragraph Fragment Elements
        - span - change style on a section of text
        - i - italicize
        - b - bold
        - a - anchor, for hyperlinking to other places within the document, or other documents entirely
        - em - emphasis
        - small - reduces font size by 1
        - abbr - for abbreviation
            - In reality, it creates a tooltip over the text for the ‘abbreviation’

### Lists

- Ordered List
    - ol = ordered list
    - li = list item
- Unordered List
    - ul = unordered list
- Definition List
    - dl = definition list
    - dt = definition term
    - dd = definition description

### Paths

- Can be relative, starting with ‘.’ or ‘..’
- can also be absolute to a drive or website location

![[URL_Components.png]]

- Are case sensitive
- Images
    - use the img element
        - requires a src attribute, which is the link to the image
        - alt - description in case image cant/wont be loaded
        - JPG is highly recommended
        - PNG is good for illustrations and diagrams
        - GIF handles motion

### Forms

- One of the most important ways for communication to a server
- Used for many different reasons
    - Log user into a web app
    - Submit a transaction
    - Upload a photo
    - Edit a profile
    - Play a game
    - etc.
- Can have an ‘action’ attribute
    - Contains the URL to the resource on the server that will response
- Some of the child elements:
    - Input - for submitting data
    - Text Area - for large amounts of text data
    - Select - for drop down lists or scrollable lists
    - Field Set - for grouping inputs, text areas, and selects together
        - can have multiple groupings on a large form (core contact info, avatar, history, etc)
        - Can have a legend(eg, a label)
- Input Element
    - Very versatile. Renders differently based on its Type attribute.
        - button, checkbox, color, date, datetime, datetime-local, email, file, hidden
        - image, month, number, password, radio, range
        - reset, search, submit, tel, text, time, url, week
    - Other attributes:
        - autofocus - the default field in the form that is automatically selected when the page is loaded
        - checked - for _radio_ and _checkbox,_ and represents selection
        - disabled - cant be interacted with
        - min/max - minimum and maximum values for numbers/dates
        - list - refers to a data list for input, such as predefined options
        - multiple - allows multiple files to be selected for _email_ and _file_
        - name - the name of the input. Useful for JavaScript
        - pattern - a regular expression, defines the type of character data allowed
        - placeholder - visual hunt for what the input expects
        - readonly - doesn’t accept new input, but can be interacted with
        - required - user must supply data for the input
        - step - the step value (eg. 2)
        - value - the value for the input

### Plugin Elements

- Object element: Nested browser content, legacy at this point.
- Embed element: New to HTML, but has been supported by browsers for some time.
- Audio - for Audio clips
- Video - for video clips
- iframe - nested browser content
    - Used for pretty much everything.
    - Youtube videos, audio files, PDF documents, videos, SVG, etc.
    - Works with fameworks, eg. Twitters Bootstrap.
    - Allows elements and scripts inside
    - Supported by all current browsers

### Canvas

- Used for drawing
    - can be 2 or 3d
    - uses WebGL
    - Allows JS to use your PCs graphics processing hardware

### Div and Span

  

### Semantic Elements

- SEO and meta information
    - section - defines a section of the page
    - header - defines the header
    - footer - defines the footer
    - nav - navigation portion/panel of the page
    - article - primary content of the page
        - can have sections within articles
    - aside - extra content (e.g. sidebar)
    - figure - annotated images for content
    - mark - section of text that is ‘marked’
    - time - content that is time/date related
    - meter - content that is a fraction (e.g. disk usage)
    - progress - a progress bar!